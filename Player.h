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
	const int8_t* sceneStatus_;
public:
	void SetInput(Input* input);
	void Init(Input* input, int8_t* sceneStatus);
	void Move();
	void Jump();
	void UpData();
	void Draw();
};

