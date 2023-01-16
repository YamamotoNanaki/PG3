#include "GamePlay.h"
#include "DxLib.h"
#include "SceneManager.h"
#include "Input.h"

void GamePlay::Update()
{
	if (Input::Instance()->Trigger())SceneManager::Instance()->ChangeScene(SceneManager::Instance()->GAMECLEAR);
}

void GamePlay::Draw()
{
	SetBackgroundColor(0x30, 0xaa, 0x30);
	DrawFormatString(100, 300, 0xffffff, "NowScene : GamePlay");
	DrawFormatString(100, 400, 0xffffff, "Press Space to Scene Change");
}
