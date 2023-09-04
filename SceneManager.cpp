#include "SceneManager.h"

void SceneManager::Init()
{
	sceneStatus_ = Title;
	field_ = std::make_unique<Field>();
	field_->Init();
	input_ = std::make_unique<Input>();
	player_ = std::make_unique<Player>();
	player_->Init(input_.get(), &sceneStatus_, field_.get());
}


void SceneManager::Update()
{
	input_->Update();

	field_->Update();
	player_->UpData();
}

void SceneManager::Draw()
{
	field_->Draw();
	player_->Draw();
}
