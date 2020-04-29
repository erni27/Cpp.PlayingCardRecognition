#include "ImageSaver.h"

void ImageSaver::SaveSingle(const cv::Mat& image, std::string path, std::string fileName) {
	cv::imwrite(path + fileName + ".png", image);
}
void ImageSaver::SaveMultiple(std::vector<cv::Mat> images, std::string path, std::string fileName) {
	for (int i = 0; i < images.size(); i++) {
		ImageSaver::SaveSingle(images[i], path, fileName + std::to_string(i));
	}
}