#pragma once

#include<stdint.h>
#include<array>
#include<vector>
#include<list>
#include<memory>
#include"Int2.h"
#include <DxLib.h>

// �E�B���h�E����
const int32_t WIN_WIDTH = 1536;

// �E�B���h�E�c��
const int32_t WIN_HEIGHT = 864;

//�u���b�N�T�C�Y
const int32_t BLOCK_SIZE = 32;

//�t�B�[���h�̉���
const size_t FIELD_WIDTH = WIN_WIDTH / BLOCK_SIZE;

//�t�B�[���h�̏c��
const size_t FIELD_HEIGHT = WIN_HEIGHT / BLOCK_SIZE;

//�t���[���̉���
const size_t FRAME_WIDTH = 4;

//�t���[���̏c��
const size_t FRAME_HEIGHT = 5;

//�}�b�v�̉���
const size_t MAP_WIDTH = FIELD_WIDTH - FRAME_WIDTH * 2;

//�}�b�v�̏c��
const size_t MAP_HEIGHT = FIELD_HEIGHT - FRAME_HEIGHT * 2;

const size_t MINO_SIZE = 5;

const size_t MINO_FALL_INTERVAL_TIMER = 10;

const size_t MINO_GRACE_TIME = 200;

const uint8_t GOAL_NUM = 5;

//�~�m�������
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