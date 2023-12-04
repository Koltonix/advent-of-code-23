#pragma once
#include "Day.h"

#include <iostream>
#include <unordered_map>;

enum D2Colour
{
	Red,
	Green,
	Blue
};

constexpr const std::string& D2ColourToString(const D2Colour& InColour)
{
	switch (InColour)
	{
	case D2Colour::Red:
		return "Red";
	case D2Colour::Green:
		return "Green";
	case D2Colour::Blue:
		return "Blue";
	default:
		throw std::invalid_argument("Unimplemented Enum!");
	}
};

class DayTwo : public Day
{
public:
	DayTwo();
	~DayTwo() {};

	virtual std::string GetDayName() const override;
	virtual std::vector<std::string> Exec() override;

private:
	int GetMaxColour(const D2Colour& InColour) const;

	int GetAllGameValues(const std::vector<std::string>& InGames) const;
	int GetGameValue(const std::string& InGame) const;

private:
	std::string mInputFilePath;
	std::string mGameIdentifier;

	std::unordered_map<D2Colour, int> MaxColourCount;
};

