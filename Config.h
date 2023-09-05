#pragma once

#include<stdint.h>
#include<array>
#include<vector>
#include<list>
#include<memory>
#include"Int2.h"
#include <DxLib.h>

// ウィンドウ横幅
const int32_t WIN_WIDTH = 1536;

// ウィンドウ縦幅
const int32_t WIN_HEIGHT = 864;

//ブロックサイズ
const int32_t BLOCK_SIZE = 32;

//フィールドの横幅
const size_t FIELD_WIDTH = WIN_WIDTH / BLOCK_SIZE;

//フィールドの縦幅
const size_t FIELD_HEIGHT = WIN_HEIGHT / BLOCK_SIZE;

//フレームの横幅
const size_t FRAME_WIDTH = 4;

//フレームの縦幅
const size_t FRAME_HEIGHT = 5;

//マップの横幅
const size_t MAP_WIDTH = FIELD_WIDTH - FRAME_WIDTH * 2;

//マップの縦幅
const size_t MAP_HEIGHT = FIELD_HEIGHT - FRAME_HEIGHT * 2;

const size_t MINO_SIZE = 5;

const size_t MINO_FALL_INTERVAL_TIMER = 10;

const size_t MINO_GRACE_TIME = 200;

const uint8_t GOAL_NUM = 5;

//ミノ押せる回数
const uint8_t MINO_PUSH_NUM = 2;

enum FieldBlockIndex : int8_t
{
	NONE,
	WALL,
	GHOST_BLOCK,
	GREEN_BLOCK,
	RED_BLOCK,
	BLUE_BLOCK,
	ORANGE_BLOCK,
};

enum MinoColorType
{
	BLUE,
	RED,
	GREEN,
	ORANGE,

	MINOCOLORTYPE_COUNT

};