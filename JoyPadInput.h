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
	// 左スティックを左右どっちの方向にどのくらい倒しているか
	int GetLeftX();

	// 左スティックを上下どっちの方向にどのくらい倒しているか
	int GetLeftY();
	int GetLeftHorizontal();
	int GetLeftVertical();
	int GetRightHorizontal();
	int GetRightVertical();
};
extern JoyPadInput pad;