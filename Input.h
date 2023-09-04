#pragma once
#include "KeyBoardInput.h"
#include "JoyPadInput.h"
#include "MouseInput.h"
class Input
{
public:
	KeyBoardInput key;
	JoyPadInput joypad;
	MouseInput mouse;
	void Update();
};

