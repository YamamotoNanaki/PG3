#include "Title.h"
#include "DxLib.h"
#include "SceneManager.h"

void Title::Update()
{
	key = CheckHitKey(KEY_INPUT_SPACE);
	if (!oldkey&&key)SceneManager::Instance()->ChangeScene(SceneManager::Instance()->NEWGAME);
	oldkey = key;
}

void Title::Draw()
{
	SetBackgroundColor(0x30, 0x30, 0x30);
	DrawFormatString(100, 300, 0xffffff, "NowScene : Title");
	DrawFormatString(100, 400, 0xffffff, "Press Space to Scene Change");
}
