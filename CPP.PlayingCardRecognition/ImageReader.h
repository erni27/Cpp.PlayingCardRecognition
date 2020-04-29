#pragma once
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

// class responsible for loading an image from file
class ImageReader
{
private:
	ImageReader();
public:
	// main method
	static cv::Mat Read(std::string imagePath, int colorFlag);
};
