#include "DxLib.h"
#include "JoyPadInput.h"



// 更新処理
void JoyPadInput::Update()
{
	// パッドのスティック状態を取得
	GetJoypadAnalogInput(&ax, &ay, DX_INPUT_PAD1);			//左スティック
	GetJoypadAnalogInputRight(&bx, &by, DX_INPUT_PAD1);		//右スティック

	// 最新のキーボード情報だったものは1フレーム前のパッド情報として保存
	oldbutton = button;

	// 最新のパッド情報を取得
	button = GetJoypadInputState(DX_INPUT_PAD1);

	// パッドが振動する処理
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

// パットの振動
void JoyPadInput::Vibration(int Power, int Timer)
{
	vibrationPower = Power;
	vibrationTimer = Timer;
}

// ボタンを長押しの時
bool JoyPadInput::GetButton(int button)
{
	return (this->button & button);
}

// ボタンを押した瞬間
bool JoyPadInput::GetButtonTrigger(int button)
{
	return (this->button & button) && !(oldbutton & button);
}

// ボタンを離した瞬間
bool JoyPadInput::GetButtonReleased(int button)
{
	return !(this->button & button) && (oldbutton & button);
}

// 左スティックを左右どっちの方向にどのくらい倒しているか
int JoyPadInput::GetLeftX()
{
	return ax;
}

// 左スティックを上下どっちの方向にどのくらい倒しているか
int JoyPadInput::GetLeftY()
{
	return ay;
}

// 左スティックの左右どちらに入力しているか(戻り値は-1,0,1)
int JoyPadInput::GetLeftHorizontal()
{
	if (ax > 300) return 1;
	if (ax < -300) return -1;
	return 0;
}

// 左スティックの上下どちらに入力しているか(戻り値は-1,0,1)
int JoyPadInput::GetLeftVertical()
{
	if (ay > 300) return 1;
	if (ay < -300) return -1;
	return 0;
}

// 右スティックの左右どちらに入力しているか(戻り値は-1,0,1)
int JoyPadInput::GetRightHorizontal()
{
	if (bx > 300) return 1;
	if (bx < -300) return -1;
	return 0;
}

// 右スティックの上下どちらに入力しているか(戻り値は-1,0,1)
int JoyPadInput::GetRightVertical()
{
	if (by > 300) return 1;
	if (by < -300) return -1;
	return 0;
}