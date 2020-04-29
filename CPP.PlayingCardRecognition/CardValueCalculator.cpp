#include "CardValueCalculator.h"


int CardValueCalculator::Calculate(const cv::Mat& cardImage) {
	int value;
	// preprocess card image
	cv::Mat workingImage = cardImage.clone();
	cv::medianBlur(workingImage, workingImage, 5);
	cv::cvtColor(workingImage, workingImage, cv::COLOR_BGR2GRAY);
	cv::threshold(workingImage, workingImage, 0, 255, cv::THRESH_BINARY | cv::THRESH_OTSU);

	// find symbol contours
	std::vector<cv::Vec4i> hierarchy;
	std::vector<std::vector<cv::Point>> contours;
	cv::findContours(workingImage, contours, hierarchy, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);

	// find only this symbols which represent card value
	contours = SymbolContourFinder::Find(contours, hierarchy);
	value = contours.size()-4;
	return value;
}