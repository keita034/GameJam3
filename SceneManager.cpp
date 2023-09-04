#include "SceneManager.h"

void SceneManager::Init()
{
	sceneStatus_ = Title;
	field_ = std::make_unique<Field>();
	field_->Init();
	input_ = std::make_unique<Input>();
	player_ = std::make_unique<Player>();
	player_->Init(input_.get(), &sceneStatus_);
}


void SceneManager::Update()
{
	input_->Update();
	player_->UpData();
	field_->Update();
}

void SceneManager::Draw()
{
	field_->Draw();
	player_->Draw();
}
