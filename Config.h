#pragma once

#include<stdint.h>

// ウィンドウ横幅
const int32_t WIN_WIDTH = 1280;

// ウィンドウ縦幅
const int32_t WIN_HEIGHT = 704;

//ブロックサイズ
const int32_t BLACK_SIZE = 32;

//マップの横幅
const size_t FIELD_WIDTH = WIN_WIDTH / BLACK_SIZE;

//マップの縦幅
const size_t FIELD_HEIGHT = WIN_HEIGHT / BLACK_SIZE;

enum FieldBlockIndex : int8_t
{
	NONE,
	WALL,
	GREEN_BLOCK,
};