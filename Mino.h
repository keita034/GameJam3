#pragma once
#include"Config.h"

class Mino
{
public:

	Mino() = default;
	~Mino() = default;

	const std::array<std::array<uint8_t, MINO_SIZE>, MINO_SIZE>& GetMino();

	const uint8_t GetMino(size_t width, size_t height);

	void SetMino(size_t width, size_t height, int8_t value);

	/// <summary>
	/// 初期化
	/// </summary>
	void Init(const Int2& pos, MinoColorType color, int8_t rot = 0);

	/// <summary>
	/// 更新
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

	void Rotate();

	void Push(int32_t num);

	Int2 GetPosIndex(size_t width, size_t height);

	void Invalidate();
	void InvalidateFall();

	bool IsValid();
	bool IsFall();

	void Down();

	MinoColorType GetMinoColor();

	enum BlockIndex
	{
		NUME,
		BLOCK
	};

private:
	bool isValid_ = false;
	bool isFall_ = false;
	bool isGround = true;
	int32_t graceTime;
	Int2 position_;
	int32_t timer_ = 0;
	int8_t pushCount_ = 0;
	MinoColorType color_;
	std::array<std::array<uint8_t, MINO_SIZE>, MINO_SIZE>mino_ = { {{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}} };
};

