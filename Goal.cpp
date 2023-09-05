#include "Goal.h"


void Goal::Update()
{
	falseGoalAddIndex_ = 0;
	for (auto& falseGoalPos : goalFalsePositions_)
	{
		falseGoalPos = { 0,0 };
	}
	for (auto& goalPos : goalPositions_)
	{
		if (beFilledGoal(goalPos))
		{
			goalFalsePositions_[falseGoalAddIndex_] = goalPos;
			falseGoalAddIndex_++;
		}
	}
}

void Goal::Draw()
{
	DrawBox(static_cast<int32_t>(position_.x - size_.x / 2),
		static_cast<int32_t>(position_.y - size_.y),
		static_cast<int32_t>(position_.x + size_.x / 2),
		static_cast<int32_t>(position_.y + size_.y),
		0xf0e68c, true);
}

Vec2 Goal::GetPos()
{
	return Vec2(position_.x,position_.y);
}

Vec2 Goal::GetSize()
{
	return size_;
}

bool Goal::Choice()
{
	uint8_t index = GetRand(goalPositions_.size() - 1);
	std::array<bool, GOAL_NUM> indexs;
	indexs[index] = true;
	while (isFalseGoal(index))
	{
		index = GetRand(goalPositions_.size() - 1);
		if (indexs[index] == true)
		{
			index++;
			if (index >= goalPositions_.size())
			{
				index = 0;
			}
		}
		indexs[index] = true;
		bool isEnd = true;
		for (auto&i : indexs)
		{
			if (i != false)
			{
				isEnd = false;
				break;
			}
		}
		if (isEnd)
		{
			return false;
		}
	}
	position_ = goalPositions_[index];
	return true;
}

bool Goal::isFalseGoal(uint8_t index)
{
	for (auto& falseGoalPos : goalFalsePositions_)
	{
		if (goalPositions_[index] == falseGoalPos)
		{
			return true;
		}
	}
	return false;
}

bool Goal::beFilledGoal(const Int2& position)
{
	float radius = size_.x / 2.0f;


	int32_t downLeftX = static_cast<int32_t>((position.x - radius + 1) / BLOCK_SIZE);
	int32_t downRightX = static_cast<int32_t>((position.x + radius - 1) / BLOCK_SIZE);

	int32_t downLeftY = static_cast<int32_t>((position.y + size_.y) / BLOCK_SIZE);
	int32_t downRightY = static_cast<int32_t>((position.y + size_.y) / BLOCK_SIZE);

	if (field_->GetMaptChipData(downLeftX, downLeftY) == FieldBlockIndex::NONE &&
		field_->GetMaptChipData(downRightX, downRightY) == FieldBlockIndex::NONE)
	{
		return false;
	}

	int32_t topLeftX = static_cast<int32_t>((position.x - radius + 1) / BLOCK_SIZE);
	int32_t topRightX = static_cast<int32_t>((position.x + radius - 1) / BLOCK_SIZE);

	int32_t topLeftY = static_cast<int32_t>((position.y - size_.y) / BLOCK_SIZE);
	int32_t topRightY = static_cast<int32_t>((position.y - size_.y) / BLOCK_SIZE);

	if (field_->GetMaptChipData(topLeftX, topLeftY) == FieldBlockIndex::NONE &&
		field_->GetMaptChipData(topRightX, topRightY) == FieldBlockIndex::NONE)
	{
		return false;
	}
	return true;
}

void Goal::Init(Field* field)
{
	size_ = { BLOCK_SIZE - 2,BLOCK_SIZE - 2 };
	field_ = field;
	goalPositions_[0] = { 1000,250 };
	goalPositions_[1] = { 1050,350 };
	goalPositions_[2] = { 400,300 };
	goalPositions_[3] = { 800,250 };
	goalPositions_[4] = { 600,250 };
	Choice();
}



