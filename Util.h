#pragma once
#include<string>
#include<vector>
#include<Windows.h>
#include<filesystem>

class Vec2;
std::vector<std::string> GetFileNames(const std::string& folderPath_);
bool BoxCollision(Vec2 obj1Pos, Vec2 obj1size, Vec2 obj2Pos, Vec2 obj2size);