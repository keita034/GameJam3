#pragma once
class JoyPadInput
{
private:
	int ax, ay;
	int bx, by;
	int button;
	int oldbutton;
	int vibrationPower;
	int vibrationTimer;
public:
	JoyPadInput();
	void Update();
	void Vibration(int Power, int Timer);
	bool GetButton(int button);
	bool GetButtonTrigger(int button);
	bool GetButtonReleased(int button);
	// ���X�e�B�b�N�����E�ǂ����̕����ɂǂ̂��炢�|���Ă��邩
	int GetLeftX();

	// ���X�e�B�b�N���㉺�ǂ����̕����ɂǂ̂��炢�|���Ă��邩
	int GetLeftY();
	int GetLeftHorizontal();
	int GetLeftVertical();
	int GetRightHorizontal();
	int GetRightVertical();
};
extern JoyPadInput pad;