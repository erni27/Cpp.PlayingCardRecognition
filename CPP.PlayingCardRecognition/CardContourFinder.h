#pragma once
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

// class reponsible for finding cards contours
class CardContourFinder
{
private:
	CardContourFinder();
public:
	// main method
	static std::vector<std::vector<cv::Point>> Find(std::vector <std::vector<cv::Point>> contours, std::vector<cv::Vec4i> hierarchy);
};

