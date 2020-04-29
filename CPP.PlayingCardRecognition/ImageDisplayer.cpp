#include "ImageDisplayer.h"

ImageDisplayer::ImageDisplayer(const cv::Mat& image) {
	if (image.empty()) {
		throw std::invalid_argument("Image is empty!");
	}
	this->image = image.clone();
}

void ImageDisplayer::Display(std::string windowName) {
	cv::namedWindow(windowName, cv::WINDOW_NORMAL);
	cv::imshow(windowName, image);
	cv::waitKey(0);
}

void ImageDisplayer::DisplayContours(std::vector<std::vector<cv::Point>> contours, std::vector<cv::Vec4i> hierarchy, std::string windowName) {
	if (contours.size() > 0 && hierarchy.size() > 0) {
		imageWithContours = cv::Mat::zeros(image.size(), CV_8UC3);
		cv::RNG rng;
		for (int i = 0; i < contours.size(); i++) {
			cv::Scalar color = cv::Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
			cv::drawContours(imageWithContours, contours, i, color, 2, 8, hierarchy, 0, cv::Point());
		}
		cv::namedWindow(windowName, cv::WINDOW_NORMAL);
		cv::imshow(windowName, imageWithContours);
		cv::waitKey(0);
	}
	else {
		throw std::invalid_argument("Vector of contours or hierarchy is empty!");
	}
}
