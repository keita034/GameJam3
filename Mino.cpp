#include "Mino.h"

#include<DxLib.h>

const std::array<std::array<uint8_t, MINO_SIZE>, MINO_SIZE>& Mino::GetMino()
{
	return mino_;
}

const uint8_t Mino::GetMino(size_t width, size_t height)
{
	return mino_[height][width];
}

void Mino::SetMino(size_t width, size_t height, int8_t value)
{
	mino_[height][width] = value;
}

void Mino::Init(const Int2& pos, MinoType type, int8_t rot)
{
	position_ = pos;
	pushCount_ = 0;

	isValid = true;
	isFall = true;
	graceTime = MINO_GRACE_TIME;
}

void Mino::Update()
{
	if (isFall)
	{
		timer_++;

		if (timer_ == MINO_FALL_INTERVAL_TIMER)
		{
			position_.y++;
			timer_ = 0;
		}
	}
	else
	{
		graceTime--;

		if (graceTime <= 0)
		{
			isValid = false;
		}
	}
}

void Mino::Draw()
{
	for (int32_t i = 0; i < MINO_SIZE; i++)
	{
		for (int32_t j = 0; j < MINO_SIZE; j++)
		{
			if (mino_[i][j] == BLOCK)
			{
				DrawBox(BLOCK_SIZE * (j - 2 + position_.x), BLOCK_SIZE * (i - 2 + position_.y), BLOCK_SIZE + BLOCK_SIZE * (j - 2 + position_.x), BLOCK_SIZE + BLOCK_SIZE * (i - 2 + position_.y), GetColor(255, 0, 0), true);
			}
		}
	}
}

void Mino::Rotate()
{
	for (size_t i = 0; i < MINO_SIZE; i++)
	{
		for (size_t j = i; j < MINO_SIZE; j++)
		{
			int8_t f = mino_[i][j];
			mino_[i][j] = mino_[j][i];
			mino_[j][i] = f;
		}
	}
}

void Mino::Push()
{
	if (pushCount_ == 0)
	{
		position_.x += 2;
		pushCount_++;
	}
}

Int2 Mino::GetPosIndex(size_t width, size_t height)
{
	return { int32_t(width - 2 + position_.x) ,int32_t(height - 2 + position_.y) };
}

void Mino::Invalidate()
{
	isValid = false;
}

void Mino::InvalidateFall()
{
	isFall = false;
}

bool Mino::IsValid()
{
	return isValid;
}
