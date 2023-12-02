#include "Utilities.h"

#include <assert.h>
#include <ostream>
#include <sstream>
#include <urlmon.h>

bool Utilities::DownloadFileFromURL(const std::string& InURL, const std::string& InDownloadPath)
{
	std::wstring url = std::wstring(InURL.begin(), InURL.end());
	std::wstring downloadPath = std::wstring(InDownloadPath.begin(), InDownloadPath.end());

	const HRESULT result = URLDownloadToFile(NULL, url.c_str(), downloadPath.c_str(), BINDF_GETNEWESTVERSION, NULL);
	return SUCCEEDED(result);
}

std::ifstream Utilities::GetFile(const std::string& InFilePath)
{
	std::ifstream file = std::ifstream(InFilePath);
	assert(file.is_open(), sFileReadErrorMsg);
	
	return file;
}

std::string Utilities::ReadFile(const std::string& InFilePath)
{
	std::ifstream file = GetFile(InFilePath);

	std::stringstream buffer = std::stringstream();
	buffer << file.rdbuf();

	return buffer.str();
}

std::vector<std::string> Utilities::ReadFileLine(const std::string& InFilePath)
{
	std::ifstream file = GetFile(InFilePath);

	std::string line = "";
	std::vector<std::string> lines = {};

	while (std::getline(file, line))
	{
		lines.push_back(line);
	}

	return lines;
}

const std::string Utilities::GetInputFilesDownloadLocation()
{
	return "../inputs/";
}
