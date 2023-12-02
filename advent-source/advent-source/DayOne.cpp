#include "DayOne.h"

#include "Utilities.h"

DayOne::DayOne()
{
}

std::vector<std::string> DayOne::Exec()
{
    // First Puzzle
    const std::string inputFileLocation = Utilities::GetInputFilesDownloadLocation() + "day1/input1.txt";
    const int firstAnswer = CalculateCalibrationValue(Utilities::ReadFileLine(inputFileLocation));

    // Second Puzzle

    return { std::to_string(firstAnswer) };
}

int DayOne::CalculateCalibrationValue(const std::vector<std::string>& InParsedInput) const
{
    int CombinedTotal = 0;
    for (const std::string& line : InParsedInput)
    {   
        CombinedTotal += GrabCombinedDigits(line);
    }

    return CombinedTotal;
}

int DayOne::GrabCombinedDigits(const std::string& InParse) const
{
    std::pair<char*, char*> digits = { nullptr, nullptr };
    for (const char& character : InParse)
    {
        if (isdigit(character))
        {
            if (digits.first == nullptr)
            {
                digits.first = new char(character);
            }

            digits.second = new char(character);
        }
    }

    // No digits were found.
    if (!digits.first || !digits.second)
    {
        return 0;
    }

    std::string combinedDigits;
    combinedDigits += *digits.first;
    combinedDigits += *digits.second;

    delete digits.first;
    delete digits.second;

    return std::stoi(combinedDigits);
}
