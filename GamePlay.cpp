#include "GamePlay.h"
#include "DxLib.h"
#include "SceneManager.h"

void GamePlay::Update()
{
	key = CheckHitKey(KEY_INPUT_SPACE);
	if (!oldkey && key)SceneManager::Instance()->ChangeScene(SceneManager::Instance()->GAMECLEAR);
	oldkey = key;
}

void GamePlay::Draw()
{
	SetBackgroundColor(0x30, 0xaa, 0x30);
	DrawFormatString(100, 300, 0xffffff, "NowScene : GamePlay");
	DrawFormatString(100, 400, 0xffffff, "Press Space to Scene Change");
}
