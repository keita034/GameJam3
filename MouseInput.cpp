#include "DxLib.h"
#include "MouseInput.h"

MouseInput mouse;

void MouseInput::Update()
{
	// �}�E�X�̍��W���擾
	GetMousePoint(&x, &y);

	// �ŐV�̃}�E�X�{�^����񂾂������̂�1�t���[���O�̃p�b�h���Ƃ��ĕۑ�
	oldcrick = crick;

	// �ŐV�̃}�E�X�{�^�������擾
	crick = GetMouseInput();
}

bool MouseInput::GetCrick(int crick)
{
	return this->crick & crick;
}

bool MouseInput::GetCrickTrigger(int crick)
{
	return this->crick & crick && !(oldcrick & crick);
}

bool MouseInput::GetCrickReleased(int crick)
{
	return !(this->crick & crick) && oldcrick & crick;
}

int MouseInput::GetMouseX()
{
	return x;
}

int MouseInput::GetMouseY()
{
	return y;
}