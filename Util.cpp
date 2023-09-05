#include "Util.h"
#include "Vec2.h"
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

bool BoxCollision(Vec2 obj1Pos, Vec2 obj1size, Vec2 obj2Pos, Vec2 obj2size)
{
	Vec2 Hit = obj2Pos - obj1Pos;
	Vec2 Size = obj1size + obj2size;
	Size.x /= 2;
	Hit.x = abs(Hit.x);
	Hit.y = abs(Hit.y);
	if (Hit <= Size)
	{
		return true;
	}

	return false;
}
