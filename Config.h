#pragma once

#include<stdint.h>
#include<array>
#include<vector>
#include<list>
#include<memory>

// �E�B���h�E����
const int32_t WIN_WIDTH = 1280;

// �E�B���h�E�c��
const int32_t WIN_HEIGHT = 704;

//�u���b�N�T�C�Y
const int32_t BLOCK_SIZE = 32;

//�t�B�[���h�̉���
const size_t FIELD_WIDTH = WIN_WIDTH / BLOCK_SIZE;

//�t�B�[���h�̏c��
const size_t FIELD_HEIGHT = WIN_HEIGHT / BLOCK_SIZE;

//�t���[���̉���
const size_t FRAME_WIDTH = 2;

//�t���[���̏c��
const size_t FRAME_HEIGHT = 2;

//�}�b�v�̉���
const size_t MAP_WIDTH = FIELD_WIDTH - FRAME_WIDTH * 2;

//�}�b�v�̏c��
const size_t MAP_HEIGHT = FIELD_HEIGHT - FRAME_HEIGHT * 2;


enum FieldBlockIndex : int8_t
{
	NONE,
	WALL,
	GREEN_BLOCK,
};