#pragma once

#include "Day.h"

#include <unordered_map>

// https://adventofcode.com/2023/day/1
class DayOne : public Day
{
public:
	DayOne();
	~DayOne() {};

	virtual std::string GetDayName() const override;
	virtual std::vector<std::string> Exec() override;

private:
	int CalculateCalibrationValue(const std::vector<std::string>& InParsedInput, const bool& bIncludeSpelledOut = false) const;
	// This will be the first and last digit passed through.
	int GrabCombinedDigits(const std::string& InParse, const bool& bIncludeSpelledOut = false) const;

private:
	std::string mInputFilePath;

	std::unordered_map<std::string, char> mDigitsSpelled;
};