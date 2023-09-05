#include "Player.h"

void Player::SetInput(Input* input)
{
	inputPtr_ = input;
}

void Player::Init(Input* input, int8_t* sceneStatus, Field* field)
{
	landing_ = true;
	speed_ = { 0,0 };
	size_ = { BLOCK_SIZE - 2,BLOCK_SIZE - 2 };
	position_ = { 900,300 };
	respownPosition_ = { 100,300 };
	for (auto& x : mapHit_)
	{
		for (auto& y : x)
		{
			y = 0;
		}
	}
	mapHit_[2][3] = 1;
	mapHit_[2][4] = 1;

	inputPtr_ = input;
	sceneStatus_ = sceneStatus;
	field_ = field;

	speed_.y = 1.0f;
	speed_.x = 3.0f;

}

void Player::Move()
{
	if (DownTopMoveCollision(speed_.y) == 1)
	{
		speed_.y = 0.0f;
		landing_ = true;
	}
	else
	{
		speed_.y += gravity;
	}

	LeftRightMoveCollision(inputPtr_->key.GetHorizontal(KEY_INPUT_A, KEY_INPUT_D) * speed_.x);
	//position_.x += inputPtr_->key.GetHorizontal(KEY_INPUT_A, KEY_INPUT_D);
}

void Player::Jump()
{
	if (landing_)
	{
		if (inputPtr_->key.GetKeyTrigger(KEY_INPUT_SPACE))
		{
			landing_ = false;
			speed_.y = -20.f;
		}
	}
	else
	{
		speed_.y += 1.0f;
	}
}

void Player::Push()
{
	if (inputPtr_->key.GetKeyTrigger(KEY_INPUT_X))
	{
		if (inputPtr_->key.GetKey(KEY_INPUT_D))
		{
			if (RightCollision())
			{
				field_->RightPush();
			}
		}

		if (inputPtr_->key.GetKey(KEY_INPUT_A))
		{
			if (LeftCollision())
			{
				field_->LeftPush();
			}
		}
	}
}

void Player::UpData()
{
	Jump();
	Move();
	Push();
	Deth();
}

void Player::Draw()
{
	DrawBox(static_cast<int32_t>(position_.x - size_.x / 2),
		static_cast<int32_t>(position_.y - size_.y),
		static_cast<int32_t>(position_.x + size_.x / 2),
		static_cast<int32_t>(position_.y + size_.y),
		0x87ceeb, true);
}

bool Player::DownMoveCollision(float speed)
{
	float radius = size_.x / 2.0f;

	int32_t downLeftX = static_cast<int32_t>((position_.x - radius) / BLOCK_SIZE);
	int32_t downRightX = static_cast<int32_t>((position_.x + radius - 1) / BLOCK_SIZE);

	int32_t downLeftY = static_cast<int32_t>(((position_.y + size_.y - 1) + speed) / BLOCK_SIZE);
	int32_t downRightY = static_cast<int32_t>(((position_.y + size_.y - 1) + speed) / BLOCK_SIZE);

	if (field_->GetMaptChipData(downLeftX, downLeftY) == FieldBlockIndex::NONE &&
		field_->GetMaptChipData(downRightX, downRightY) == FieldBlockIndex::NONE)
	{
		position_.y += speed;

		return false;
	}
	else
	{

		downLeftY = static_cast<int32_t>((position_.y + size_.y - 1) / BLOCK_SIZE);
		downRightY = static_cast<int32_t>((position_.y + size_.y - 1) / BLOCK_SIZE);

		if (field_->GetMaptChipData(downLeftX, downLeftY) == FieldBlockIndex::NONE &&
			field_->GetMaptChipData(downRightX, downRightY) == FieldBlockIndex::NONE)
		{
			while (1)
			{
				downLeftY = static_cast<int32_t>(((position_.y + size_.y - 1) + 1) / BLOCK_SIZE);
				downRightY = static_cast<int32_t>(((position_.y + size_.y - 1) + 1) / BLOCK_SIZE);


				if (field_->GetMaptChipData(downLeftX, downLeftY) == FieldBlockIndex::NONE &&
					field_->GetMaptChipData(downRightX, downRightY) == FieldBlockIndex::NONE)
				{
					position_.y += 1.0f;
				}
				else
				{
					break;
				}

			}
		}

		return true;
	}
}

bool Player::TopMoveCollision(float speed)
{
	float radius = size_.x / 2.0f;

	int32_t topLeftX = static_cast<int32_t>((position_.x - radius) / BLOCK_SIZE);
	int32_t topRightX = static_cast<int32_t>((position_.x + radius - 1) / BLOCK_SIZE);

	int32_t topLeftY = static_cast<int32_t>(((position_.y - size_.y - 1) + speed) / BLOCK_SIZE);
	int32_t topRightY = static_cast<int32_t>(((position_.y - size_.y) + speed) / BLOCK_SIZE);

	if (field_->GetMaptChipData(topLeftX, topLeftY) == FieldBlockIndex::NONE &&
		field_->GetMaptChipData(topRightX, topRightY) == FieldBlockIndex::NONE)
	{
		position_.y += speed;

		return false;
	}
	else
	{
		topLeftY = static_cast<int32_t>((position_.y - size_.y) / BLOCK_SIZE);
		topRightY = static_cast<int32_t>((position_.y - size_.y) / BLOCK_SIZE);

		if (field_->GetMaptChipData(topLeftX, topLeftY) == FieldBlockIndex::NONE &&
			field_->GetMaptChipData(topRightX, topRightY) == FieldBlockIndex::NONE)
		{
			while (1)
			{
				topLeftY = static_cast<int32_t>(((position_.y - size_.y - 1)) / BLOCK_SIZE);
				topRightY = static_cast<int32_t>(((position_.y - size_.y - 1)) / BLOCK_SIZE);


				if (field_->GetMaptChipData(topLeftX, topLeftY) == FieldBlockIndex::NONE &&
					field_->GetMaptChipData(topRightX, topRightY) == FieldBlockIndex::NONE)
				{
					position_.y -= 1.0f;
				}
				else
				{
					break;
				}

			}
		}

		return true;
	}
}

bool Player::LeftMoveCollision(float speed)
{
	float radius = size_.x / 2.0f;


	int32_t topLeftX = static_cast<int32_t>(((position_.x - radius) + speed) / BLOCK_SIZE);
	int32_t downLeftX = static_cast<int32_t>(((position_.x - radius) + speed) / BLOCK_SIZE);

	int32_t topLeftY = static_cast<int32_t>((position_.y - size_.y) / BLOCK_SIZE);
	int32_t downLeftY = static_cast<int32_t>((position_.y + size_.y - 1) / BLOCK_SIZE);

	if (field_->GetMaptChipData(topLeftX, topLeftY) == FieldBlockIndex::NONE &&
		field_->GetMaptChipData(downLeftX, downLeftY) == FieldBlockIndex::NONE)
	{
		position_.x += speed;

		return false;
	}
	else
	{
		topLeftX = static_cast<int32_t>(((position_.x - radius)) / BLOCK_SIZE);
		downLeftX = static_cast<int32_t>(((position_.x - radius)) / BLOCK_SIZE);

		if (field_->GetMaptChipData(topLeftX, topLeftY) == FieldBlockIndex::NONE &&
			field_->GetMaptChipData(downLeftX, downLeftY) == FieldBlockIndex::NONE)
		{
			while (1)
			{
				topLeftX = static_cast<int32_t>(((position_.x - radius) - 1) / BLOCK_SIZE);
				downLeftX = static_cast<int32_t>(((position_.x - radius) - 1) / BLOCK_SIZE);


				if (field_->GetMaptChipData(topLeftX, topLeftY) == FieldBlockIndex::NONE &&
					field_->GetMaptChipData(downLeftX, downLeftY) == FieldBlockIndex::NONE)
				{
					position_.x -= 1;
				}
				else
				{
					break;
				}

			}
		}

		return true;
	}
}

bool Player::RightMoveCollision(float speed)
{
	float radius = size_.x / 2.0f;

	int32_t topRightX = static_cast<int32_t>(((position_.x + radius-1) + speed) / BLOCK_SIZE);
	int32_t downRightX = static_cast<int32_t>(((position_.x + radius - 1) + speed) / BLOCK_SIZE);

	int32_t topRightY = static_cast<int32_t>((position_.y - size_.y) / BLOCK_SIZE);
	int32_t downRightY = static_cast<int32_t>((position_.y + size_.y - 1) / BLOCK_SIZE);

	if (field_->GetMaptChipData(topRightX, topRightY) == FieldBlockIndex::NONE &&
		field_->GetMaptChipData(downRightX, downRightY) == FieldBlockIndex::NONE)
	{
		position_.x += speed;

		return false;
	}
	else
	{
		topRightX = static_cast<int32_t>(((position_.x + radius - 1)) / BLOCK_SIZE);
		downRightX = static_cast<int32_t>(((position_.x + radius - 1)) / BLOCK_SIZE);

		if (field_->GetMaptChipData(topRightX, topRightY) == FieldBlockIndex::NONE &&
			field_->GetMaptChipData(downRightX, downRightY) == FieldBlockIndex::NONE)
		{
			while (1)
			{
				topRightX = static_cast<int32_t>(((position_.x + radius - 1) + 1) / BLOCK_SIZE);
				downRightX = static_cast<int32_t>(((position_.x + radius - 1) + 1) / BLOCK_SIZE);


				if (field_->GetMaptChipData(topRightX, topRightY) == FieldBlockIndex::NONE &&
					field_->GetMaptChipData(downRightX, downRightY) == FieldBlockIndex::NONE)
				{
					position_.x += 1;
				}
				else
				{
					break;
				}

			}
		}

		return true;
	}
}

bool Player::Deth()
{
	if (GetCaughtHit())
	{
		position_ = respownPosition_;
		return true;
	}
	return false;
}

bool Player::GetCaughtHit()
{
	float radius = size_.x / 2.0f;


	int32_t downLeftX = static_cast<int32_t>((position_.x - radius) / BLOCK_SIZE);
	int32_t downRightX = static_cast<int32_t>((position_.x + radius - 1) / BLOCK_SIZE);

	int32_t downLeftY = static_cast<int32_t>((position_.y + size_.y) / BLOCK_SIZE);
	int32_t downRightY = static_cast<int32_t>((position_.y + size_.y) / BLOCK_SIZE);

	if (field_->GetMaptChipData(downLeftX, downLeftY + 1) == FieldBlockIndex::NONE &&
		field_->GetMaptChipData(downRightX, downRightY + 1) == FieldBlockIndex::NONE)
	{
		return false;
	}

	int32_t topLeftX = static_cast<int32_t>((position_.x - radius) / BLOCK_SIZE);
	int32_t topRightX = static_cast<int32_t>((position_.x + radius - 1) / BLOCK_SIZE);

	int32_t topLeftY = static_cast<int32_t>((position_.y - size_.y) / BLOCK_SIZE);
	int32_t topRightY = static_cast<int32_t>((position_.y - size_.y) / BLOCK_SIZE);

	if (field_->GetMaptChipData(topLeftX, topLeftY) == FieldBlockIndex::NONE &&
		field_->GetMaptChipData(topRightX, topRightY) == FieldBlockIndex::NONE)
	{
		return false;
	}
	return true;
}

bool Player::DownCollision()
{
	float radius = size_.x / 2.0f;

	int32_t downLeftX = static_cast<int32_t>((position_.x - radius) / BLOCK_SIZE);
	int32_t downRightX = static_cast<int32_t>((position_.x + radius - 1) / BLOCK_SIZE);

	int32_t downLeftY = static_cast<int32_t>((position_.y + size_.y) / BLOCK_SIZE);
	int32_t downRightY = static_cast<int32_t>((position_.y + size_.y) / BLOCK_SIZE);

	if (field_->GetMaptChipData(downLeftX, downLeftY + 1) == FieldBlockIndex::NONE &&
		field_->GetMaptChipData(downRightX, downRightY + 1) == FieldBlockIndex::NONE)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool Player::TopCollision()
{
	float radius = size_.x / 2.0f;

	int32_t topLeftX = static_cast<int32_t>((position_.x - radius) / BLOCK_SIZE);
	int32_t topRightX = static_cast<int32_t>((position_.x + radius) / BLOCK_SIZE);

	int32_t topLeftY = static_cast<int32_t>((position_.y - size_.y) / BLOCK_SIZE);
	int32_t topRightY = static_cast<int32_t>((position_.y - size_.y) / BLOCK_SIZE);

	if (field_->GetMaptChipData(topLeftX, topLeftY - 1) == FieldBlockIndex::NONE &&
		field_->GetMaptChipData(topRightX, topRightY - 1) == FieldBlockIndex::NONE)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool Player::LeftCollision()
{
	float radius = size_.x / 2.0f;

	int32_t topLeftX = static_cast<int32_t>(((position_.x - radius)) / BLOCK_SIZE);
	int32_t downLeftX = static_cast<int32_t>(((position_.x - radius)) / BLOCK_SIZE);

	int32_t topLeftY = static_cast<int32_t>((position_.y - size_.y) / BLOCK_SIZE);
	int32_t downLeftY = static_cast<int32_t>((position_.y + size_.y - 1) / BLOCK_SIZE);

	if (field_->GetMaptChipData(topLeftX - 1, topLeftY) == FieldBlockIndex::NONE &&
		field_->GetMaptChipData(downLeftX - 1, downLeftY) == FieldBlockIndex::NONE)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool Player::RightCollision()
{
	float radius = size_.x / 2.0f;

	int32_t topRightX = static_cast<int32_t>(((position_.x + size_.x - 1)) / BLOCK_SIZE);
	int32_t downRightX = static_cast<int32_t>(((position_.x + size_.x - 1)) / BLOCK_SIZE);

	int32_t topRightY = static_cast<int32_t>((position_.y - size_.y) / BLOCK_SIZE);
	int32_t downRightY = static_cast<int32_t>((position_.y + size_.y - 1) / BLOCK_SIZE);

	if (field_->GetMaptChipData(topRightX + 1, topRightY) == FieldBlockIndex::NONE &&
		field_->GetMaptChipData(downRightX + 1, downRightY) == FieldBlockIndex::NONE)
	{
		return false;
	}
	else
	{
		return true;
	}
}

int32_t Player::DownTopMoveCollision(float speed)
{
	if (speed >= 0)
	{
		if (DownMoveCollision(speed))
		{
			return 1;
		}
		else
		{
			return 0;
		}

	}
	else
	{
		if (TopMoveCollision(speed))
		{
			return 2;
		}
		else
		{
			return 0;
		}
	}
}

int32_t Player::LeftRightMoveCollision(float speed)
{
	if (speed >= 0)
	{
		if (RightMoveCollision(speed))
		{
			return 2;
		}
		else
		{
			return 0;
		}

	}
	else
	{
		if (LeftMoveCollision(speed))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
}
