#include "DxLib.h"
#include "KeyBoardInput.h"

KeyBoardInput key;

// 更新処理
void KeyBoardInput::Update()
{
	// 最新のキーボード情報だったものは1フレーム前のキーボード情報として保存
	for (int i = 0; i < 256; i++)
	{
		oldkeys[i] = keys[i];
	}

	// 最新のキーボード情報を取得
	GetHitKeyStateAll(keys);
}

// キーを長押しの時
bool KeyBoardInput::GetKey(int key)
{
	return keys[key];
}

// キーを押した瞬間
bool KeyBoardInput::GetKeyTrigger(int key)
{
	return keys[key] && !oldkeys[key];
}

//キーを離した瞬間
bool KeyBoardInput::GetKeyReleased(int key)
{
	return !keys[key] && oldkeys[key];
}

// キーの左右どちらに入力しているか(戻り値は-1,0,1)
int KeyBoardInput::GetHorizontal(int leftKey, int rightKey)
{
	return keys[rightKey] - keys[leftKey];
}

// キーの上下どちらに入力しているか(戻り値は-1,0,1)
int KeyBoardInput::GetVertical(int downKey, int upKey)
{
	return keys[upKey] - keys[downKey];
}