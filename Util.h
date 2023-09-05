#pragma once
#include<string>
#include<vector>
#include<Windows.h>
#include<filesystem>
#include <fstream>

std::vector<std::string> GetFileNames(const std::string& folderPath_);

std::string GetFileName(std::string& path_);