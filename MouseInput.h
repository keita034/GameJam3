#pragma once
class MouseInput
{
private:
	int x, y;
	int crick;
	int oldcrick;
public:
	void Update();
	bool GetCrick(int mouse);
	bool GetCrickTrigger(int mouse);
	bool GetCrickReleased(int mouse);
	int GetMouseX();
	int GetMouseY();
};
extern MouseInput mouse;