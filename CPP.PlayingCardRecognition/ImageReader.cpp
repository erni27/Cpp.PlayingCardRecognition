#include "ImageReader.h"

cv::Mat ImageReader::Read(std::string imagePath, int colorFlag) {
	cv::Mat image = cv::imread(imagePath, colorFlag);
	if (image.empty()) {
		throw std::invalid_argument("Wrong file path!");
	}
	return image;
}