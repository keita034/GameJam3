#include "DxLib.h"
#include "KeyBoardInput.h"

KeyBoardInput key;

// �X�V����
void KeyBoardInput::Update()
{
	// �ŐV�̃L�[�{�[�h��񂾂������̂�1�t���[���O�̃L�[�{�[�h���Ƃ��ĕۑ�
	for (int i = 0; i < 256; i++)
	{
		oldkeys[i] = keys[i];
	}

	// �ŐV�̃L�[�{�[�h�����擾
	GetHitKeyStateAll(keys);
}

// �L�[�𒷉����̎�
bool KeyBoardInput::GetKey(int key)
{
	return keys[key];
}

// �L�[���������u��
bool KeyBoardInput::GetKeyTrigger(int key)
{
	return keys[key] && !oldkeys[key];
}

//�L�[�𗣂����u��
bool KeyBoardInput::GetKeyReleased(int key)
{
	return !keys[key] && oldkeys[key];
}

// �L�[�̍��E�ǂ���ɓ��͂��Ă��邩(�߂�l��-1,0,1)
int KeyBoardInput::GetHorizontal(int leftKey, int rightKey)
{
	return keys[rightKey] - keys[leftKey];
}

// �L�[�̏㉺�ǂ���ɓ��͂��Ă��邩(�߂�l��-1,0,1)
int KeyBoardInput::GetVertical(int downKey, int upKey)
{
	return keys[upKey] - keys[downKey];
}