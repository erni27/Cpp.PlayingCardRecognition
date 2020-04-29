#include "SymbolContourFinder.h"

// find the largest contour area
double SymbolContourFinder::GetMaxContourArea(std::vector <std::vector<cv::Point>> contours) {
	double maxArea = 0;
	double newArea;
	for (int i = 0; i < contours.size(); i++) {
		newArea = cv::contourArea(contours.at(i));
		if (newArea > maxArea) {
			maxArea = newArea;
		}
	}
	return maxArea;
}

// find card symbols without any noise
std::vector<std::vector<cv::Point>> SymbolContourFinder::Find(std::vector <std::vector<cv::Point>> contours, std::vector<cv::Vec4i> hierarchy) {
	std::vector <std::vector<cv::Point>> symbolContours;
	cv::Vec4i temp;
	for (int i = 0; i < contours.size(); i++) {
		temp = hierarchy[i];
		// if contour does not have a child and has a parent
		if (temp[2] == -1 && temp[3] != -1)
			symbolContours.push_back(contours[i]);
	}
	// find the largest contour area
	double maxArea = SymbolContourFinder::GetMaxContourArea(symbolContours);
	std::vector <std::vector<cv::Point>> finalSymbolContours;
	for (int i = 0; i < symbolContours.size(); i++) {
		// if contour area is bigger than 1% the largest area
		// it helps in contours denoise 
		if (cv::contourArea(contours.at(i)) > maxArea * 0.01)
			finalSymbolContours.push_back(symbolContours[i]);
	}
	return finalSymbolContours;
}

