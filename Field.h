#pragma once
#include"Config.h"

#include"Mino.h"

#include<map>

struct Line
{
	std::array<int8_t, FIELD_WIDTH>line{};
	int16_t blockCount = 0;
};

class Field
{
public:

	//�R���X�g���N�^�E�f�X�g���N�^
	Field() = default;
	~Field() = default;

	/// <summary>
	/// ������
	/// </summary>
	void Init();

	/// <summary>
	/// �X�V
	/// </summary>
	void Update();

	/// <summary>
	/// �`��
	/// </summary>
	void Draw();

	/// <summary>
	/// ���Z�b�g
	/// </summary>
	void Reset();

	void FieldReset();

	void RightPush();
	void LeftPush();

	/// <summary>
	/// �}�b�v�`�b�v�̃f�[�^�擾
	/// </summary>
	/// <param name="width">��</param>
	/// <param name="height">�c</param>
	int8_t GetChipData(size_t width, size_t height);

	int8_t GetMaptChipData(size_t width, size_t height);

	void SetMino(Mino* mino);

private:

	//�}�b�v�`�b�v�̃f�[�^
	std::array<Line, FIELD_HEIGHT>field_;

	std::unique_ptr<Mino> minos_;
	Mino* mino_;

};

