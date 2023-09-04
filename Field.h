#pragma once
#include<array>

#include"Config.h"

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

	/// <summary>
	/// マップチップのデータ取得
	/// </summary>
	/// <param name="width">横</param>
	/// <param name="height">縦</param>
	int8_t GetChipData(size_t width, size_t height);

	/// <summary>
	/// マップチップのデータを設定
	/// </summary>
	/// <param name="width">横</param>
	/// <param name="height">縦</param>
	/// <param name="value">値</param>
	void SetChipData(size_t width, size_t height, int8_t value);

private:

	//マップチップのデータ
	std::array<Line, FIELD_HEIGHT>field_;

};

