#include "GameClear.h"
#include "DxLib.h"
#include "SceneManager.h"

void GameClear::Update()
{
	key = CheckHitKey(KEY_INPUT_SPACE);
	if (!oldkey && key)SceneManager::Instance()->ChangeScene(SceneManager::Instance()->TITLE);
	oldkey = key;
}

void GameClear::Draw()
{
	SetBackgroundColor(0x30, 0x30, 0xaa);
	DrawFormatString(100, 300, 0xffffff, "NowScene : GameClear");
	DrawFormatString(100, 400, 0xffffff, "Press Space to Scene Change");
}
