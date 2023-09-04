#pragma once
#include<array>

#include"Config.h"
#include"Int2.h"

class Mino
{
public:

	Mino() = default;
	~Mino() = default;

	const std::array<std::array<uint8_t, MINO_SIZE>, MINO_SIZE>& GetMino();

	const uint8_t GetMino(size_t width, size_t height);

	void SetMino(size_t width, size_t height, int8_t value);

	/// <summary>
	/// ������
	/// </summary>
	void Init(const Int2& pos, MinoType type, int8_t rot = 0);

	/// <summary>
	/// �X�V
	/// </summary>
	void Update();

	/// <summary>
	/// �`��
	/// </summary>
	void Draw();

	void Rotate();

	void Push();

	Int2 GetPosIndex(size_t width, size_t height);

	void Invalidate();
	void InvalidateFall();

	bool IsValid();

	enum BlockIndex
	{
		NUME,
		BLOCK
	};

private:
	bool isValid = false;
	bool isFall = false;
	int32_t graceTime;
	Int2 position_;
	int32_t timer_ = 0;
	int8_t pushCount_ = 0;
	std::array<std::array<uint8_t, MINO_SIZE>, MINO_SIZE>mino_ = { {{0,0,0,0,0},{0,0,0,0,0},{1,1,1,1,1},{0,0,0,0,0},{0,0,0,0,0}} };
};

