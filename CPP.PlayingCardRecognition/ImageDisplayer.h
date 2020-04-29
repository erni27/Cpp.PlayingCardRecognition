#pragma once
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

class ImageDisplayer
{
private:
	cv::Mat image;
	cv::Mat imageWithContours;
public:
	ImageDisplayer(const cv::Mat& image); 
	~ImageDisplayer();
	void Display(std::string windowName = "Image");
	void DisplayContours(std::vector <std::vector<cv::Point>> contours, std::vector<cv::Vec4i> hierarchy, std::string windowName = "ImageWithContours");
};

