#pragma once
#include"Config.h"
#include"Field.h"
#include "Input.h"
#include "Player.h"
class SceneManager
{
	enum SceneStatus
	{
		Title,
		Game,
		Result
	};
	int8_t sceneStatus_;
	std::unique_ptr<Field> field_;
	std::unique_ptr<Input> input_;
	std::unique_ptr<Player> player_;
	std::unique_ptr<Goal> goal_;
public:
	void Init();
	void Update();
	void Draw();
};

