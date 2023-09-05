#include "Util.h"

std::vector<std::string> GetFileNames(const std::string& folderPath_)
{
	std::filesystem::directory_iterator lDirectoryIterator(folderPath_), lIteratorEnd;
	std::error_code lErrorCode;
	std::vector<std::string> lFileNames;

	for (; lDirectoryIterator != lIteratorEnd && !lErrorCode; lDirectoryIterator.increment(lErrorCode))
	{
		const std::filesystem::directory_entry lEntry = *lDirectoryIterator;

		lFileNames.push_back(lEntry.path().string());
	}

	return lFileNames;
}

std::string GetFileName(std::string& path_)
{
	std::filesystem::path lFilePath = path_;

	return lFilePath.stem().string();
}
