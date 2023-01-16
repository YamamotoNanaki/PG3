#include "Title.h"
#include "DxLib.h"
#include "SceneManager.h"
#include "Input.h"

void Title::Update()
{
	if (Input::Instance()->Trigger())SceneManager::Instance()->ChangeScene(SceneManager::Instance()->NEWGAME);
}

void Title::Draw()
{
	SetBackgroundColor(0x30, 0x30, 0x30);
	DrawFormatString(100, 300, 0xffffff, "NowScene : Title");
	DrawFormatString(100, 400, 0xffffff, "Press Space to Scene Change");
}
