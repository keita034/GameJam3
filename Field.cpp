#include "Field.h"

#include<DxLib.h>

void Field::Init()
{
	Reset();
}

void Field::Update()
{

}

void Field::Draw()
{
	for (size_t i= 0; i < FIELD_HEIGHT; i++)
	{
		for (size_t j = 0; j < FIELD_WIDTH; j++)
		{
			if (field_[i].line[j] == FieldBlockIndex::WALL)
			{
				DrawBox(BLACK_SIZE * j, BLACK_SIZE * i, BLACK_SIZE + BLACK_SIZE * j, BLACK_SIZE + BLACK_SIZE * i, GetColor(100, 100, 100), true);
				DrawBox(BLACK_SIZE * j, BLACK_SIZE * i, BLACK_SIZE + BLACK_SIZE * j, BLACK_SIZE + BLACK_SIZE * i, GetColor(255, 255, 255), false);
			}
			else if(field_[i].line[j] == FieldBlockIndex::GREEN_BLOCK)
			{
				DrawBox(BLACK_SIZE * j, BLACK_SIZE * i, BLACK_SIZE + BLACK_SIZE * j, BLACK_SIZE + BLACK_SIZE * i, GetColor(0, 255, 0), true);
			}
		}
	}
}

void Field::Reset()
{
	for (size_t i = 0; i < FIELD_HEIGHT; i++)
	{
		for (size_t j = 0; j < FIELD_WIDTH; j++)
		{
			if (i < FRAME_HEIGHT || i >= FIELD_HEIGHT - FRAME_HEIGHT || j < FRAME_WIDTH || j >= FIELD_WIDTH - FRAME_WIDTH)
			{
				field_[i].line[j] = FieldBlockIndex::WALL;
			}
			else
			{
				field_[i].line[j] = FieldBlockIndex::NONE;

			}
		}
	}
}

int8_t Field::GetChipData(size_t width, size_t height)
{
	return field_[height + FRAME_HEIGHT].line[width + FRAME_WIDTH];
}

void Field::SetChipData(size_t width, size_t height, int8_t value)
{
	field_[height + FRAME_HEIGHT].line[width + FRAME_WIDTH] = value;
}
