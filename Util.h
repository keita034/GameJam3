#pragma once
#include<string>
#include<vector>
#include<Windows.h>
#include<filesystem>
#include <fstream>

std::vector<std::string> GetFileNames(const std::string& folderPath_);

std::string GetFileName(std::string& path_);
class Vec2;
std::vector<std::string> GetFileNames(const std::string& folderPath_);
bool BoxCollision(Vec2 obj1Pos, Vec2 obj1size, Vec2 obj2Pos, Vec2 obj2size);