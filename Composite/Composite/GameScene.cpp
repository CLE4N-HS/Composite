#include "GameScene.h"

GameScene::GameScene()
{
	// Parent constructor called first
}

GameScene::~GameScene()
{
	// Child destructor called first
}

void GameScene::Update()
{
	// override but do parent Update
	Scene::Update();
}
