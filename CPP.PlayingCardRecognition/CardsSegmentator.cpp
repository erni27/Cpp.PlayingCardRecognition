#include "CardsSegmentator.h"

// load an image
CardsSegmentator::CardsSegmentator(const cv::Mat& image) {
	if (image.empty())
		throw std::invalid_argument("Image is empty!");
	this->image = image.clone();
}

// segment method
std::vector<cv::Mat> CardsSegmentator::Segment() {
	std::vector<cv::Mat> cards;

	// image preprocessing
	cv::Mat workingImage;
	cv::medianBlur(this->image, workingImage, 5);
	cv::cvtColor(workingImage, workingImage, cv::COLOR_BGR2GRAY);
	cv::threshold(workingImage, workingImage, 0, 255, cv::THRESH_BINARY | cv::THRESH_OTSU);

	// finding cards contours
	std::vector<cv::Vec4i> hierarchy;
	std::vector<std::vector<cv::Point>> contours;
	cv::findContours(workingImage, contours, hierarchy, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);
	if (contours.size() == 0)
		throw std::invalid_argument("Cannot find card contour");
	try {
		// finding specific contours 
		contours = CardContourFinder::Find(contours, hierarchy);
	}
	catch (const std::invalid_argument & exception) {
		throw exception;
	}

	cv::Mat singleCard;
	for (int i = 0; i < contours.size(); i++) {
		// perform perspective transformation on a found card 
		singleCard = SkewCorrector::Correct(this->image, contours[i]);
		// store segmented card image in a vector
		cards.push_back(singleCard);
	}
	return cards;
}