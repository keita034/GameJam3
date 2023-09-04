#include "DxLib.h"
#include "MouseInput.h"



void MouseInput::Update()
{
	// マウスの座標を取得
	GetMousePoint(&x, &y);

	// 最新のマウスボタン情報だったものは1フレーム前のパッド情報として保存
	oldcrick = crick;

	// 最新のマウスボタン情報を取得
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