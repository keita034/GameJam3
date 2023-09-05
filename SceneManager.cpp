#include "SceneManager.h"

void SceneManager::Init()
{
	sceneStatus_ = Title;
	field_ = std::make_unique<Field>();
	field_->Init();
	input_ = std::make_unique<Input>();
	goal_ = std::make_unique<Goal>();
	goal_->Init(field_.get());
	player_ = std::make_unique<Player>();
	player_->Init(input_.get(), &sceneStatus_, field_.get(),goal_.get());
}


void SceneManager::Update()
{
	input_->Update();

	goal_->Update();
	player_->UpData();
	field_->Update();
}

void SceneManager::Draw()
{
	field_->Draw();
	goal_->Draw();
	player_->Draw();
}
