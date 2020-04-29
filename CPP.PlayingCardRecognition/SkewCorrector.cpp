#include "SkewCorrector.h"

// rearrange the points order
std::vector<cv::Point2f> SkewCorrector::Order(std::vector<cv::Point> points) {
	std::vector<cv::Point2f> orderedPoints(4);
	double sumXY[4], diffXY[4];
	for (int i = 0; i < points.size(); i++) {
		sumXY[i] = points[i].x + points[i].y;
		diffXY[i] = points[i].y - points[i].x;
	}

	// points must be in the following order:
	// topleft -> topright -> bottomright -> bottomleft
	orderedPoints[0] = points[std::distance(sumXY, std::find(sumXY, sumXY + 4, *std::min_element(sumXY, sumXY + 4)))];
	orderedPoints[2] = points[std::distance(sumXY, std::find(sumXY, sumXY + 4, *std::max_element(sumXY, sumXY + 4)))];
	orderedPoints[1] = points[std::distance(diffXY, std::find(diffXY, diffXY + 4, *std::min_element(diffXY, diffXY + 4)))];
	orderedPoints[3] = points[std::distance(diffXY, std::find(diffXY, diffXY + 4, *std::max_element(diffXY, diffXY + 4)))];

	return orderedPoints;
}

// calculate new size method
cv::Size SkewCorrector::CalculateNewSize(std::vector<cv::Point> points) {
	cv::Point topLeft, topRight, bottomRight, bottomLeft;
	topLeft = points[0];
	topRight = points[1];
	bottomRight = points[2];
	bottomLeft = points[3];
	double widthA = sqrt(pow(topRight.x - topLeft.x, 2) + pow(topRight.y - topLeft.y,2));
	double widthB = sqrt(pow(bottomRight.x - bottomLeft.x, 2) + pow(bottomRight.y - bottomLeft.y, 2));
	double width = MAX(widthA, widthB);

	double heightA = sqrt(pow(bottomLeft.x - topLeft.x, 2) + pow(bottomLeft.y - topLeft.y, 2));
	double heightB = sqrt(pow(bottomRight.x - topRight.x, 2) + pow(bottomRight.y - topRight.y, 2));
	double height = MAX(heightA, heightB);

	return cv::Size(width, height);
}
cv::Mat SkewCorrector::Correct(const cv::Mat& image, std::vector<cv::Point> contour) {
	if (image.empty())
		throw std::invalid_argument("Image is empty!");
	if (contour.size() != 4)
		throw std::invalid_argument("Invalid contour format!");
	cv::Mat workingImage = image.clone();
	// arrange the points in the right order for a later perspective transformation
	std::vector<cv::Point2f> currentPoints = SkewCorrector::Order(contour);

	// calculate a new size of the single card 
	cv::Size newSize = SkewCorrector::CalculateNewSize(contour);

	// assign new card points in the right order for a later perspective transformation
	std::vector<cv::Point2f> newPoints(4);
	newPoints[0] = cv::Point2f(0, 0);
	newPoints[1] = cv::Point2f(newSize.width - 1, 0);
	newPoints[2] = cv::Point2f(newSize.width - 1, newSize.height - 1);
	newPoints[3] = cv::Point2f(0, newSize.height-1);
	
	// perspective transformation
	cv::Mat card;
	cv::Mat T = cv::getPerspectiveTransform(currentPoints, newPoints);
	cv::warpPerspective(workingImage, card, T, newSize);

	return card;
}