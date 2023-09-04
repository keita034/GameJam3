#pragma once

#include<stdint.h>

// �E�B���h�E����
const int32_t WIN_WIDTH = 1280;

// �E�B���h�E�c��
const int32_t WIN_HEIGHT = 704;

//�u���b�N�T�C�Y
const int32_t BLACK_SIZE = 32;

//�}�b�v�̉���
const size_t FIELD_WIDTH = WIN_WIDTH / BLACK_SIZE;

//�}�b�v�̏c��
const size_t FIELD_HEIGHT = WIN_HEIGHT / BLACK_SIZE;

enum FieldBlockIndex : int8_t
{
	NONE,
	WALL,
	GREEN_BLOCK,
};