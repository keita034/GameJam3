#pragma once
#include"Config.h"

#include"Mino.h"

#include<map>
#include<string>

struct Line
{
	std::array<int8_t, FIELD_WIDTH>line{};
	int16_t blockCount = 0;
};

class Field
{
public:

	//コンストラクタ・デストラクタ
	Field() = default;
	~Field() = default;

	/// <summary>
	/// 初期化
	/// </summary>
	void Init();

	/// <summary>
	/// 更新
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

	/// <summary>
	/// リセット
	/// </summary>
	void Reset();

	void FieldReset();

	void RightPush();
	void LeftPush();

	/// <summary>
	/// マップチップのデータ取得
	/// </summary>
	/// <param name="width">横</param>
	/// <param name="height">縦</param>
	int8_t GetChipData(size_t width, size_t height);

	int8_t GetMaptChipData(size_t width, size_t height);

	void SetMino(Mino* mino);

	void LoadMino();

	void MinoAppearance();

private:

	//マップチップのデータ
	std::array<Line, FIELD_HEIGHT>field_;

	std::map<std::string, std::unique_ptr<Mino>>minos_;
	std::vector<std::string>minoFileNames;
	Mino* mino_;
	Mino* nextMino_;
	std::vector<Int2>appearancePoint{};
};

