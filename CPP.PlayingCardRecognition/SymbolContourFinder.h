#pragma once
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

// class reponsible for finding card symbols
class SymbolContourFinder
{
private:
	SymbolContourFinder();
	// method responsible for finding contour max area from given contours
	static double GetMaxContourArea(std::vector <std::vector<cv::Point>> contours);
public:
	// main method
	static std::vector<std::vector<cv::Point>> Find(std::vector <std::vector<cv::Point>> contours, std::vector<cv::Vec4i> hierarchy);
};


