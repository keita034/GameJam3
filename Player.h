#pragma once
#include "DxLib.h"
#include "Config.h"
#include "Vec2.h"
#include "Input.h"
#include "Field.h"
#include "Goal.h"

class Player
{
	enum MoveStatus
	{
		Moveing,
		Attack
	};

	enum class VirticalHit
	{
		None,
		Top,
		Down
	};

	enum class HorizonHit
	{
		None,
		Left,
		Right
	};

	Vec2 position_;
	Vec2 respownPosition_;
	Vec2 speed_;
	Vec2 size_;
	Input* inputPtr_;
	Field* field_;
	Goal* goal_;
	bool landing_;
	bool isGround = false;;
	uint16_t actionStatus_;
	std::array<std::array<uint8_t, 5>, 5> mapHit_;
	float gravity = 1.0f;
	const int8_t* sceneStatus_;
	size_t point_;
public:
	void SetInput(Input* input);
	void Init(Input* input, int8_t* sceneStatus, Field* field,Goal* goal);
	void Move();
	void Jump();
	void Push();
	void UpData();
	void Draw();

	bool DownMoveCollision(float speed);
	bool TopMoveCollision(float speed);
	bool LeftMoveCollision(float speed);
	bool RightMoveCollision(float speed);

	bool Deth();
	bool GetCaughtHit();

	bool DownCollision();
	bool TopCollision();
	bool LeftCollision();
	bool RightCollision();

	bool IsGoal();
	/// <summary>
	/// yのスピードを足しながら当たり判定処理
	/// </summary>
	/// <param name="speed">スピード</param>
	/// <returns>0なら当たってない、1なら下が当たってる、2なら上が当たってる</returns>
	int32_t DownTopMoveCollision(float speed);

	/// <summary>
	/// xのスピードを足しながら当たり判定処理
	/// </summary>
	/// <param name="speed">スピード</param>
	/// <returns>0なら当たってない、1なら左が当たってる、2なら右が当たってる</returns>
	int32_t LeftRightMoveCollision(float speed);
};

