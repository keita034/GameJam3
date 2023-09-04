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
			if (GetChipData(j, i) == FieldBlockIndex::WALL)
			{
				DrawBox(BLACK_SIZE * j, BLACK_SIZE * i, BLACK_SIZE + BLACK_SIZE * j, BLACK_SIZE + BLACK_SIZE * i, GetColor(100, 100, 100), true);
			}
			else if(GetChipData(j, i) == FieldBlockIndex::GREEN_BLOCK)
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
			if (i == 0 || i == FIELD_HEIGHT - 1 || j == 0 || j == FIELD_WIDTH - 1)
			{
				SetChipData(j, i, FieldBlockIndex::WALL);
			}
		}

	}
}

int8_t Field::GetChipData(size_t width, size_t height)
{
	return field_[height].line[width];
}

void Field::SetChipData(size_t width, size_t height, int8_t value)
{
	field_[height].line[width] = value;
}
