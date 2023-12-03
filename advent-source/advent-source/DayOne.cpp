#include "DayOne.h"

#include "Utilities.h"

DayOne::DayOne()
{
    mInputFilePath = Utilities::GetInputFilesDownloadLocation() + "day1/input1.txt";

    mDigitsSpelled =
    {
        {"ZERO", '0'},
        {"ONE", '1'},
        {"TWO", '2'},
        {"THREE", '3'},
        {"FOUR", '4'},
        {"FIVE", '5'},
        {"SIX" , '6'},
        {"SEVEN", '7'},
        {"EIGHT", '8'},
        {"NINE", '9'}
    };
}

std::string DayOne::GetDayName() const
{
    return "Day One";
}

std::vector<std::string> DayOne::Exec()
{
    std::vector<std::string> file = Utilities::ReadFileLine(mInputFilePath);
    
    // First Puzzle
    const int firstAnswer = CalculateCalibrationValue(file);
    // Second Puzzle
    const int secondAnswer = CalculateCalibrationValue(file, true);

    return { std::to_string(firstAnswer), std::to_string(secondAnswer)};
}

int DayOne::CalculateCalibrationValue(const std::vector<std::string>& InParsedInput, const bool& bIncludeSpelledOut) const
{
    int CombinedTotal = 0;
    for (const std::string& line : InParsedInput)
    {   
        CombinedTotal += GrabCombinedDigits(line, bIncludeSpelledOut);
    }

    return CombinedTotal;
}

int DayOne::GrabCombinedDigits(const std::string& InParse, const bool& bIncludeSpelledOut) const
{
    std::pair<char*, char*> digits = { nullptr, nullptr };

    const auto assignDigitOrder = [&digits](const char& InChar)
    {
        if (digits.first == nullptr)
        {
            digits.first = new char(InChar);
        }

        digits.second = new char(InChar);
    };

    for (int i = 0; i < InParse.size(); i++)
    {
        const char& character = InParse[i];
        if (isdigit(character))
        {
            assignDigitOrder(character);
        }
        else if (bIncludeSpelledOut)
        {   
            std::string spelledOut = { static_cast<char>(std::toupper(character)) };
            for (int j = i + 1; j <= InParse.size(); j++)
            {
                // This doesn't include text when it's been appended; e.g: EADFNINEEIGHT will not pick up ANHYTHING.
                for (const std::pair<std::string, char>& it : mDigitsSpelled)
                {
                    size_t val = it.first.find(spelledOut);
                    if (val != std::string::npos && spelledOut.size() >= it.first.size())
                    {
                        const char& digitFound = mDigitsSpelled.at(spelledOut);
                        assignDigitOrder(digitFound);

                        i = j - 2;
                        spelledOut = "";
                        break;
                    }
                }

                // Break clause for the for loop above. I want a double break, essentially.
                // And I don't to use a bool.
                if (spelledOut.size() == 0)
                {
                    break;
                }

                const char& innerCharacter = InParse[j];
                if (isdigit(innerCharacter))
                {
                    break;
                }
                else
                {
                    spelledOut += static_cast<char>(std::toupper(innerCharacter));
                }
            }
        }
    }

    // No digits were found.
    if (!digits.first || !digits.second)
    {
        return 0;
    }

    const std::string combinedStr = { *digits.first, *digits.second };

    delete digits.first;
    delete digits.second;

    return std::stoi(combinedStr);
}
