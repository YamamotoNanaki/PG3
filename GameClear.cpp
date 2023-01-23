#include "GameClear.h"
#include "DxLib.h"
#include "SceneManager.h"
#include "Input.h"

void GameClear::Update()
{
	if (Input::Instance()->Trigger(KEY_INPUT_SPACE))SceneManager::Instance()->ChangeScene(SceneManager::Instance()->TITLE);
}

void GameClear::Draw()
{
	SetBackgroundColor(0x30, 0x30, 0xaa);
	DrawFormatString(100, 300, 0xffffff, "NowScene : GameClear");
	DrawFormatString(100, 400, 0xffffff, "Press Space to Scene Change");
}
