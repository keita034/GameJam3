#pragma once
#include<array>

#include"Config.h"
#include"Int2.h"

#include"Mino.h"
#include<memory>

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

	/// <summary>
	/// マップチップのデータ取得
	/// </summary>
	/// <param name="width">横</param>
	/// <param name="height">縦</param>
	int8_t GetChipData(size_t width, size_t height);

	void SetMino(Mino* mino);

private:

	//マップチップのデータ
	std::array<Line, FIELD_HEIGHT>field_;

	std::unique_ptr<Mino> minos_;
	Mino* mino_;

};

