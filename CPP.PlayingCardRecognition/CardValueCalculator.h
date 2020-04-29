#pragma once
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include "SymbolContourFinder.h"

// class reponsible for calculating card value
class CardValueCalculator
{
private:
	CardValueCalculator();
public: 
	// main method
	static int Calculate(const cv::Mat& cardImage);
};

