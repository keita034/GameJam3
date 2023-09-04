#pragma once

#include<stdint.h>
#include<array>
#include<vector>
#include<list>
#include<memory>

// ウィンドウ横幅
const int32_t WIN_WIDTH = 1280;

// ウィンドウ縦幅
const int32_t WIN_HEIGHT = 704;

//ブロックサイズ
const int32_t BLOCK_SIZE = 32;

//フィールドの横幅
const size_t FIELD_WIDTH = WIN_WIDTH / BLOCK_SIZE;

//フィールドの縦幅
const size_t FIELD_HEIGHT = WIN_HEIGHT / BLOCK_SIZE;

//フレームの横幅
const size_t FRAME_WIDTH = 2;

//フレームの縦幅
const size_t FRAME_HEIGHT = 2;

//マップの横幅
const size_t MAP_WIDTH = FIELD_WIDTH - FRAME_WIDTH * 2;

//マップの縦幅
const size_t MAP_HEIGHT = FIELD_HEIGHT - FRAME_HEIGHT * 2;


enum FieldBlockIndex : int8_t
{
	NONE,
	WALL,
	GREEN_BLOCK,
};