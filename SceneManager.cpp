#include "SceneManager.h"
#include "Title.h"
#include "NewGame.h"
#include "GamePlay.h"
#include "GameClear.h"

using namespace std;

SceneManager* SceneManager::Instance()
{
	static SceneManager inst;
	return &inst;
}

void SceneManager::ChangeScene(int sceneNo)
{
	delete scene;
	switch (sceneNo)
	{
	case TITLE:
		scene = new Title;
		break;
	case NEWGAME:
		scene = new NewGame;
		break;
	case GAMEPLAY:
		scene = new GamePlay;
		break;
	case GAMECLEAR:
		scene = new GameClear;
		break;
	default:
		scene = new Title;
		break;
	}
}

void SceneManager::Update()
{
	scene->Update();
}

void SceneManager::Draw()
{
	scene->Draw();
}
