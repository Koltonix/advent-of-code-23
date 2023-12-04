#include "Day.h"
#include "DayOne.h"
#include "DayTwo.h"

#include <iostream>
#include <vector>

int main()
{
    // Only doing a ptr because I want an abstract class lol.
    std::vector<Day*> days =
    {
        new DayOne(),
        new DayTwo()
    };

    for (Day* day : days)
    {
        if (day)
        {
            const std::string& dayName = day->GetDayName();
            std::vector<std::string> results = day->Exec();

            for (const std::string& result : results)
            {
                std::cout << dayName << ": " << result << std::endl;
            }

            delete day;
            day = nullptr;
        }
    };

    days.clear();
    return 1;
}