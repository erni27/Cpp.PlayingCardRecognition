#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include<map>
#include "ImageDisplayer.h"
#include "ImageReader.h"
#include "CardsSegmentator.h"
#include "CardValueCalculator.h"
#include "ImageSaver.h"

int main()
{
	// map containing all input data
	std::map<std::string, cv::Mat> images;

	// vector containing segmented cards from image
	std::vector<cv::Mat> singleCardImages;

	// vector containing cards values
	std::vector<int> cardValues;

	// load input data
	try {
		images["original"] = ImageReader::Read("assets/12390186-2019-11-20-142723.png", 1);
		images["blur"] = ImageReader::Read("assets/12390186-2019-11-20-142723_blur.png", 1);
		images["gradient"] = ImageReader::Read("assets/12390186-2019-11-20-142723_gradient.png", 1);
		images["salt_pepper"] = ImageReader::Read("assets/12390186-2019-11-20-142723_salt_pepper.png", 1);
	}
	catch(const std::invalid_argument& exception) {
		std::cout << exception.what();
		return 1;
	}

	// select the image on which the algorithm will be run
	cv::Mat image = images.at("salt_pepper").clone();

	try {
		// object responsible for card segmentation
		CardsSegmentator* cardsSegmentator = new CardsSegmentator(image);
		singleCardImages = cardsSegmentator->Segment();
		delete cardsSegmentator;
	}
	catch (const std::invalid_argument & exception) {
		std::cout << exception.what();
		return 1;
	}

	for (int i = 0; i<singleCardImages.size(); i++) {
		cardValues.push_back(CardValueCalculator::Calculate(singleCardImages[i]));
	}

	// sort card values 
	std::sort(cardValues.begin(), cardValues.end());

	// display result
	std::cout << "Sorted cards values: " << std::endl;
	for (int i = 0; i < cardValues.size(); i++) {
		std::cout << cardValues[i] << std::endl;
	}

	// save segmented cards images
	ImageSaver::SaveMultiple(singleCardImages, "output/", "card");
	return 0;
}