#include "DxLib.h"
#include "JoyPadInput.h"

JoyPadInput pad;

// �X�V����
void JoyPadInput::Update()
{
	// �p�b�h�̃X�e�B�b�N��Ԃ��擾
	GetJoypadAnalogInput(&ax, &ay, DX_INPUT_PAD1);			//���X�e�B�b�N
	GetJoypadAnalogInputRight(&bx, &by, DX_INPUT_PAD1);		//�E�X�e�B�b�N

	// �ŐV�̃L�[�{�[�h��񂾂������̂�1�t���[���O�̃p�b�h���Ƃ��ĕۑ�
	oldbutton = button;

	// �ŐV�̃p�b�h�����擾
	button = GetJoypadInputState(DX_INPUT_PAD1);

	// �p�b�h���U�����鏈��
	if (vibrationTimer > 0)
	{
		vibrationTimer--;
		StartJoypadVibration(DX_INPUT_PAD1, 1000, 1000);
	}
	if (vibrationTimer <= 0)
	{
		vibrationTimer = 0;
		StopJoypadVibration(DX_INPUT_PAD1);
	}
}

JoyPadInput::JoyPadInput()
{
	vibrationPower = 0;
	vibrationTimer = 0;
}

// �p�b�g�̐U��
void JoyPadInput::Vibration(int Power, int Timer)
{
	vibrationPower = Power;
	vibrationTimer = Timer;
}

// �{�^���𒷉����̎�
bool JoyPadInput::GetButton(int button)
{
	return (this->button & button);
}

// �{�^�����������u��
bool JoyPadInput::GetButtonTrigger(int button)
{
	return (this->button & button) && !(oldbutton & button);
}

// �{�^���𗣂����u��
bool JoyPadInput::GetButtonReleased(int button)
{
	return !(this->button & button) && (oldbutton & button);
}

// ���X�e�B�b�N�����E�ǂ����̕����ɂǂ̂��炢�|���Ă��邩
int JoyPadInput::GetLeftX()
{
	return ax;
}

// ���X�e�B�b�N���㉺�ǂ����̕����ɂǂ̂��炢�|���Ă��邩
int JoyPadInput::GetLeftY()
{
	return ay;
}

// ���X�e�B�b�N�̍��E�ǂ���ɓ��͂��Ă��邩(�߂�l��-1,0,1)
int JoyPadInput::GetLeftHorizontal()
{
	if (ax > 300) return 1;
	if (ax < -300) return -1;
	return 0;
}

// ���X�e�B�b�N�̏㉺�ǂ���ɓ��͂��Ă��邩(�߂�l��-1,0,1)
int JoyPadInput::GetLeftVertical()
{
	if (ay > 300) return 1;
	if (ay < -300) return -1;
	return 0;
}

// �E�X�e�B�b�N�̍��E�ǂ���ɓ��͂��Ă��邩(�߂�l��-1,0,1)
int JoyPadInput::GetRightHorizontal()
{
	if (bx > 300) return 1;
	if (bx < -300) return -1;
	return 0;
}

// �E�X�e�B�b�N�̏㉺�ǂ���ɓ��͂��Ă��邩(�߂�l��-1,0,1)
int JoyPadInput::GetRightVertical()
{
	if (by > 300) return 1;
	if (by < -300) return -1;
	return 0;
}