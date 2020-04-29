#pragma once
class SpecificContourFinder
{
public:
	static virtual std::vector<std::vector<cv::Point>> Find() = 0;
};

