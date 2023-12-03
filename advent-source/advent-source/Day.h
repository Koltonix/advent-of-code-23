#pragma once

#include <string>
#include <vector>

class Day
{
public:
	virtual std::string GetDayName() const = 0;
	virtual std::vector<std::string> Exec() = 0;
};