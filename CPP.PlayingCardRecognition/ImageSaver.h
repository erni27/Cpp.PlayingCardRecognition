#pragma once
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

class ImageSaver {
private:
	ImageSaver();
public:
	// saving single image
	static void SaveSingle(const cv::Mat& image, std::string path, std::string fileName = "image");
	// saving images stored in a vector
	static void SaveMultiple(std::vector<cv::Mat> images, std::string path, std::string fileName = "image");
};

