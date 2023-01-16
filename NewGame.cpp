#include "NewGame.h"
#include "DxLib.h"
#include "SceneManager.h"
#include "Input.h"

void NewGame::Update()
{
	if (Input::Instance()->Trigger())SceneManager::Instance()->ChangeScene(SceneManager::Instance()->GAMEPLAY);
}

void NewGame::Draw()
{
	SetBackgroundColor(0xaa, 0x30, 0x30);
	DrawFormatString(100, 300, 0xffffff, "NowScene : NewGame");
	DrawFormatString(100, 400, 0xffffff, "Press Space to Scene Change");
}
