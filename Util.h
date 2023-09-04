#pragma once
#include<string>
#include<vector>
#include<Windows.h>
#include<filesystem>

std::vector<std::string> getFileNames(const std::string& folderPath_)
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