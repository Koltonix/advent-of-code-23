#pragma once

#include "Day.h"

// https://adventofcode.com/2023/day/1
class DayOne : public Day
{
public:
	DayOne();
	~DayOne() {};

	virtual std::vector<std::string> Exec() override;

private:
	int CalculateCalibrationValue(const std::vector<std::string>& InParsedInput) const;
	// This will be the first and last digit passed through.
	int GrabCombinedDigits(const std::string& InParse) const;

private:
	std::string mInputFilePath;
};