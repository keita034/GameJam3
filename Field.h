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

	/// <summary>
	/// �}�b�v�`�b�v�̃f�[�^�擾
	/// </summary>
	/// <param name="width">��</param>
	/// <param name="height">�c</param>
	int8_t GetChipData(size_t width, size_t height);

	/// <summary>
	/// �}�b�v�`�b�v�̃f�[�^��ݒ�
	/// </summary>
	/// <param name="width">��</param>
	/// <param name="height">�c</param>
	/// <param name="value">�l</param>
	void SetChipData(size_t width, size_t height, int8_t value);

private:

	//�}�b�v�`�b�v�̃f�[�^
	std::array<Line, FIELD_HEIGHT>field_;

};

