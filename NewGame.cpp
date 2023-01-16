#include "NewGame.h"
#include "DxLib.h"
#include "SceneManager.h"

void NewGame::Update()
{
	key = CheckHitKey(KEY_INPUT_SPACE);
	if (!oldkey && key)SceneManager::Instance()->ChangeScene(SceneManager::Instance()->GAMEPLAY);
	oldkey = key;
}

void NewGame::Draw()
{
	SetBackgroundColor(0xaa, 0x30, 0x30);
	DrawFormatString(100, 300, 0xffffff, "NowScene : NewGame");
	DrawFormatString(100, 400, 0xffffff, "Press Space to Scene Change");
}
