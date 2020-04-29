#include "CardContourFinder.h"

// find method
std::vector<std::vector<cv::Point>> CardContourFinder::Find(std::vector <std::vector<cv::Point>> contours, std::vector<cv::Vec4i> hierarchy) {
	std::vector <std::vector<cv::Point>> cardContours;
	std::vector<cv::Point> approxContour;
	double contourPerimeter;
	cv::Vec4i temp;

	// iterate through all contours
	for (int i = 0; i < contours.size(); i++) {
		temp = hierarchy[i];
		// if contour has a child and does not have a parent 
		if (temp[2] != -1 && temp[3] == -1) {
			// count closed contour perimeter 
			contourPerimeter = cv::arcLength(contours[i], true);
			// approx contour by closed curved 
			cv::approxPolyDP(contours[i], approxContour, 0.02 * contourPerimeter, true);
			// if approx contour is quadrangle 
			if (approxContour.size() == 4) {
				cardContours.push_back(approxContour);
			}
		}
	}
	if (cardContours.size() == 0)
		throw std::invalid_argument("Cannot find any card contours on this picture");
	return cardContours;
}
