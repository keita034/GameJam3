#pragma once
#include "Config.h"
#include "Vec2.h"
#include "Field.h"
class Goal
{
	Int2 position_;
	Vec2 size_;
	Field* field_;
	std::array<Int2, GOAL_NUM>goalPositions_;
	std::array<Int2, GOAL_NUM>goalFalsePositions_;
	uint8_t falseGoalAddIndex_;
public:
	Vec2 GetPos();
	Vec2 GetSize();
	bool Choice();
	bool isFalseGoal(uint8_t index);
	bool beFilledGoal(const Int2& position);
	void Init(Field* field);
	void Update();
	void Draw();
};

