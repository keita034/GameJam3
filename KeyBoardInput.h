#pragma once
class KeyBoardInput
{
private:
	char keys[256];
	char oldkeys[256];
public:
	void Update();
	bool GetKey(int key);
	bool GetKeyTrigger(int key);
	bool GetKeyReleased(int key);
	int GetHorizontal(int leftKey, int righKey);
	int GetVertical(int downKey, int upkey);
};
