#pragma once
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include "CardContourFinder.h"
#include "ImageDisplayer.h"
#include "SkewCorrector.h"


// class consist of method reponsible for card segmentation
class CardsSegmentator
{
private:
	cv::Mat image;
public:
	CardsSegmentator(const cv::Mat& image);
	// main method
	std::vector<cv::Mat> Segment();
};

