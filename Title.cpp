#include "Title.h"
#include "DxLib.h"
#include "SceneManager.h"
#include "Input.h"

void Title::Update()
{
	//if (Input::Instance()->Trigger(KEY_INPUT_SPACE))SceneManager::Instance()->ChangeScene(SceneManager::Instance()->NEWGAME);
	enemy.Update();
}

void Title::Draw()
{
	SetBackgroundColor(0x30, 0x30, 0x30);
	DrawFormatString(100, 300, 0xffffff, "Space‚ğ‰Ÿ‚·‚Æ“G‚ªs“®‚µ‚Ü‚·");
	enemy.Draw(100, 400);

	//DrawFormatString(100, 400, 0xffffff, "Press Space to Scene Change");
}
