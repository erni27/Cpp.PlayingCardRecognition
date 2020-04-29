#pragma once
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <math.h>

// class reponsible for card perspective transformation 
class SkewCorrector
{
private:
	SkewCorrector();
	// method responsible for arranging the points in the right order
	// for a later perspective transformation
	static std::vector<cv::Point2f> Order(std::vector<cv::Point> points);

	// method reponsible for calculate real size of the single card
	static cv::Size CalculateNewSize(std::vector<cv::Point> points);
public:
	// main method
	static cv::Mat Correct(const cv::Mat& image,std::vector<cv::Point> approxContour);
};

