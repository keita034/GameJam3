#include "Player.h"

void Player::Init()
{
	landing_ = true;
}

void Player::SetInput(Input* input)
{
	inputPtr_ = input;
}

void Player::Move()
{
	position_.x += inputPtr_->key.GetHorizontal(KEY_INPUT_A,KEY_INPUT_D);
	position_.y += speed_.y;
}

void Player::Jump()
{
	if (landing_)
	{
		speed_.y = 0;
		if (inputPtr_->key.GetKeyTrigger(KEY_INPUT_SPACE))
		{
			landing_ = false;
			speed_.y = 20.f;
		}
	}
	else
	{
		speed_.y -= 1.0f;
	}
}

void Player::UpData()
{
	Jump();
	Move();
}

void Player::Draw()
{
	DrawBox(static_cast<int32_t>(position_.x - size_.x / 2),
		static_cast<int32_t>(position_.y - size_.y),
		static_cast<int32_t>(position_.x + size_.x / 2),
		static_cast<int32_t>(position_.y + size_.y),
		0x87ceeb,true);
}
