#include "Field.h"

#include<DxLib.h>

void Field::Init()
{
	minos_ = std::make_unique<Mino>();
	mino_ = minos_.get();
	mino_->Init({ 34,5 }, I, GREEN, 2);

	Reset();
}

void Field::Update()
{
	FieldReset();

	if (mino_)
	{
		mino_->Update();

		SetMino(mino_);

		if (!mino_->IsValid())
		{
			mino_ = nullptr;
		}
	}
}

void Field::Draw()
{
	for (size_t i = 0; i < FIELD_HEIGHT; i++)
	{
		for (size_t j = 0; j < FIELD_WIDTH; j++)
		{
			if (field_[i].line[j] == FieldBlockIndex::WALL)
			{
				DrawBox(BLOCK_SIZE * j, BLOCK_SIZE * i, BLOCK_SIZE + BLOCK_SIZE * j, BLOCK_SIZE + BLOCK_SIZE * i, GetColor(100, 100, 100), true);
				DrawBox(BLOCK_SIZE * j, BLOCK_SIZE * i, BLOCK_SIZE + BLOCK_SIZE * j, BLOCK_SIZE + BLOCK_SIZE * i, GetColor(255, 255, 255), false);
			}
			else if (field_[i].line[j] == FieldBlockIndex::GREEN_BLOCK)
			{
				DrawBox(BLOCK_SIZE * j, BLOCK_SIZE * i, BLOCK_SIZE + BLOCK_SIZE * j, BLOCK_SIZE + BLOCK_SIZE * i, GetColor(0, 255, 0), true);
			}
			else if (field_[i].line[j] == FieldBlockIndex::RED_BLOCK)
			{
				DrawBox(BLOCK_SIZE * j, BLOCK_SIZE * i, BLOCK_SIZE + BLOCK_SIZE * j, BLOCK_SIZE + BLOCK_SIZE * i, GetColor(255, 0, 0), true);
			}
			else if (field_[i].line[j] == FieldBlockIndex::BLUE_BLOCK)
			{
				DrawBox(BLOCK_SIZE * j, BLOCK_SIZE * i, BLOCK_SIZE + BLOCK_SIZE * j, BLOCK_SIZE + BLOCK_SIZE * i, GetColor(0, 0, 255), true);
			}
			else if (field_[i].line[j] == FieldBlockIndex::GHOST_BLOCK)
			{
				DrawBox(BLOCK_SIZE * j, BLOCK_SIZE * i, BLOCK_SIZE + BLOCK_SIZE * j, BLOCK_SIZE + BLOCK_SIZE * i, GetColor(255, 255, 255), true);
			}
		}
	}

	if (mino_)
	{
		mino_->Draw();
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

void Field::FieldReset()
{
	for (size_t i = FRAME_HEIGHT; i < MAP_HEIGHT + FRAME_HEIGHT; i++)
	{
		for (size_t j = FRAME_WIDTH; j < MAP_WIDTH + FRAME_WIDTH; j++)
		{
			if (GetMaptChipData(j, i) == FieldBlockIndex::GHOST_BLOCK)
			{
				field_[i].line[j] = FieldBlockIndex::NONE;
			}
		}
	}
}

void Field::RightPush()
{
	if (mino_)
	{
		int32_t pushNum = 0;
		bool isBreak = false;

		for (int32_t k = 1; k < 3; k++)
		{
			for (size_t i = 0; i < MINO_SIZE; i++)
			{
				for (size_t j = 0; j < MINO_SIZE; j++)
				{
					if (mino_->GetMino(j, i) == Mino::BlockIndex::BLOCK)
					{
						Int2 index = mino_->GetPosIndex(j, i);

						if(field_[index.y].line[index.x + k] != FieldBlockIndex::NONE &&
							field_[index.y].line[index.x + k] != FieldBlockIndex::GHOST_BLOCK)
						{
							pushNum = k-1;
							isBreak = true;
							break;
						}
					}
				}
				if (isBreak)break;
			}
			if (isBreak)break;

		}

		if (!isBreak)pushNum = 2;

		if (pushNum > 0)
		{
			mino_->Push(pushNum);
		}
	}
}

void Field::LeftPush()
{
	if (mino_)
	{
		int32_t pushNum = 0;
		bool isBreak = false;

		for (int32_t k = 1; k < 3; k++)
		{
			for (size_t i = 0; i < MINO_SIZE; i++)
			{
				for (size_t j = 0; j < MINO_SIZE; j++)
				{
					if (mino_->GetMino(j, i) == Mino::BlockIndex::BLOCK)
					{
						Int2 index = mino_->GetPosIndex(j, i);

						if (field_[index.y].line[index.x - k] != FieldBlockIndex::NONE &&
							field_[index.y].line[index.x - k] != FieldBlockIndex::GHOST_BLOCK)
						{
							pushNum = -(k + 1);
							isBreak = true;
							break;
						}
					}
				}
				if (isBreak)break;
			}
			if (isBreak)break;

		}

		if (!isBreak)pushNum = -2;

		if (pushNum < 0)
		{
			mino_->Push(pushNum);
		}
	}
}

int8_t Field::GetChipData(size_t width, size_t height)
{
	return field_[height + FRAME_HEIGHT].line[width + FRAME_WIDTH];
}

int8_t Field::GetMaptChipData(size_t width, size_t height)
{
	return field_[height].line[width];
}

void Field::SetMino(Mino* mino)
{
	if (mino->IsValid())
	{
		for (size_t i = 0; i < MINO_SIZE; i++)
		{
			for (size_t j = 0; j < MINO_SIZE; j++)
			{
				if (mino->GetMino(j, i) == Mino::BlockIndex::BLOCK)
				{
					Int2 index = mino->GetPosIndex(j, i);
					field_[index.y].line[index.x] = FieldBlockIndex::GHOST_BLOCK;

					if (field_[index.y + 1].line[index.x] != FieldBlockIndex::NONE && field_[index.y + 1].line[index.x] != FieldBlockIndex::GHOST_BLOCK)
					{
						mino->InvalidateFall();
					}
				}
			}
		}
	}
	else
	{
		for (size_t i = 0; i < MINO_SIZE; i++)
		{
			for (size_t j = 0; j < MINO_SIZE; j++)
			{
				if (mino->GetMino(j, i) == Mino::BlockIndex::BLOCK)
				{
					Int2 index = mino->GetPosIndex(j, i);
					field_[index.y].blockCount++;
					switch (mino->GetMinoColor())
					{
					case BLUE:
						field_[index.y].line[index.x] = FieldBlockIndex::BLUE_BLOCK;
						break;
					case RED:
						field_[index.y].line[index.x] = FieldBlockIndex::RED_BLOCK;
						break;
					case GREEN:
						field_[index.y].line[index.x] = FieldBlockIndex::GREEN_BLOCK;
						break;
					case ORANGE:
						break;
					default:
						break;
					}

				}
			}
		}
	}

}
