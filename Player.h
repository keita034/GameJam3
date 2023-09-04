#pragma once
#include "DxLib.h"
#include "Config.h"
#include "Vec2.h"
#include "Input.h"
#include"Field.h"

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
	bool landing_;
	bool isGround = false;;
	uint16_t actionStatus_;
	std::array<std::array<uint8_t, 5>, 5> mapHit_;
	float gravity = 1.0f;
	const int8_t* sceneStatus_;
public:
	void SetInput(Input* input);
	void Init(Input* input, int8_t* sceneStatus, Field* field);
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

	/// <summary>
	/// y�̃X�s�[�h�𑫂��Ȃ��瓖���蔻�菈��
	/// </summary>
	/// <param name="speed">�X�s�[�h</param>
	/// <returns>0�Ȃ瓖�����ĂȂ��A1�Ȃ牺���������Ă�A2�Ȃ�オ�������Ă�</returns>
	int32_t DownTopMoveCollision(float speed);

	/// <summary>
	/// x�̃X�s�[�h�𑫂��Ȃ��瓖���蔻�菈��
	/// </summary>
	/// <param name="speed">�X�s�[�h</param>
	/// <returns>0�Ȃ瓖�����ĂȂ��A1�Ȃ獶���������Ă�A2�Ȃ�E���������Ă�</returns>
	int32_t LeftRightMoveCollision(float speed);
};

