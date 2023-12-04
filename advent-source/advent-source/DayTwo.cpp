#include "DayTwo.h"

#include "Utilities.h"

#include <assert.h>

DayTwo::DayTwo()
{
	mInputFilePath = Utilities::GetInputFilesDownloadLocation() + "day1/input2.txt";
	mGameIdentifier = "Game";

	// I have a suspicion that the follow-up challenge will have these be dynamic.
	MaxColourCount =
	{
		{D2Colour::Red, 12},
		{D2Colour::Green, 13},
		{D2Colour::Blue, 14}
	};
}

std::string DayTwo::GetDayName() const
{
	return "Day Two";
}

std::vector<std::string> DayTwo::Exec()
{
	const std::vector<std::string> file = Utilities::ReadFileLine(mInputFilePath);

	int firstAnswer = GetAllGameValues(file);

	return std::vector<std::string>();
}

int DayTwo::GetMaxColour(const D2Colour& InColour) const
{
	if (MaxColourCount.find(InColour) != MaxColourCount.end())
	{
		return MaxColourCount.at(InColour);
	}

	assert(false, "No Enum exists in Map!");
	return -1;
}

int DayTwo::GetAllGameValues(const std::vector<std::string>& InGames) const
{
	int values = 0;
	for (const std::string& line : InGames)
	{
		values += GetGameValue(line);
	}

	return values;
}

int DayTwo::GetGameValue(const std::string& InGame) const
{
	int gameId = -1;
	std::string currentWord = "";

	// NEED TO STORE BECAUSE CHARACTERS CAN BE MULTIPLE FOR NUMBERS.

	std::unordered_map<D2Colour, int> ColourValues = {};
	for (int i = 0; i < InGame.size(); i++)
	{
		const char& character = InGame[i];
		currentWord += character;

		if (currentWord == mGameIdentifier)
		{
			// Bit hard-codey, but the values appear to be constant;
			i += 2;

			std::string gameIdStr = "";
			for (int j = i; j < InGame.size(); j++)
			{
				const char& gameIdChar = InGame[j];
				if (isdigit(gameIdChar))
				{
					gameIdStr += gameIdChar;
				}
				else
				{
					i = j;
					break;
				}
			}

			gameId = std::stoi(gameIdStr);
			currentWord = "";

			continue;
		}
		else
		{
			std::string currentNumberStr = "";
			for (int j = i; j < InGame.size(); j++)
			{
				if (isdigit)
				{
					currentNumberStr += InGame[j];
				}
				else
				{

				}
			}
		}
	}

	return 0;
}
