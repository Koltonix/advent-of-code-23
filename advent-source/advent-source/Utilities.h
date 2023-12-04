#pragma once

#include <fstream>
#include <string>
#include <vector>

class Utilities
{
public:
	static bool DownloadFileFromURL(const std::string& InURL, const std::string& InDownloadPath);
	static std::ifstream GetFile(const std::string& InFilePath);
	static std::string ReadFile(const std::string& InFilePath);
	static std::vector<std::string> ReadFileLine(const std::string& InFilePath);

	// Nevermind, I forgot each user has a different puzzle.
	static const std::string GetInputFilesDownloadLocation();

	static char GetCharAt(const std::string& InStr, const int InIndex);
};