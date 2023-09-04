#pragma once
#include "DxLib.h"
#include "Config.h"
#include "Vec2.h"
#include "Input.h"
class Player
{
	enum MoveStatus
	{
		Moveing,
		Attack
	};
	Vec2 position_;
	Vec2 speed_;
	Vec2 size_;
	Input* inputPtr_;
	bool landing_;
	uint16_t actionStatus_;
	std::array<std::array<uint8_t, 5>, 5> mapHit_;
public:
	void Init();
	void SetInput(Input* input);
	void Move();
	void Jump();
	void UpData();
	void Draw();
};

