#include "Title.h"
#include "DxLib.h"
#include "SceneManager.h"
#include "Input.h"

static const std::array<char, 10> inputKeys =
{
	KEY_INPUT_0,KEY_INPUT_1,KEY_INPUT_2,KEY_INPUT_3,KEY_INPUT_4,KEY_INPUT_5,KEY_INPUT_6,KEY_INPUT_7,KEY_INPUT_8,KEY_INPUT_9
};

void Title::Update()
{
	//if (Input::Instance()->Trigger(KEY_INPUT_SPACE))SceneManager::Instance()->ChangeScene(SceneManager::Instance()->NEWGAME);
	if (Input::Instance()->Trigger(KEY_INPUT_SPACE))
	{
		for (auto& itr : enemys)
		{
			if (itr == nullptr)
			{
				itr = new Enemy;
				break;
			}
		}
	}
	for (int i = 0; i < enemys.size(); i++)
	{
		if (enemys[i] == nullptr)
		{
			continue;
		}
		if (Input::Instance()->Trigger(inputKeys[i]))
		{
			enemys[i]->Damage();
		}
	}
	if (Enemy::GetDeathFlag())
	{
		for (auto& itr : enemys)
		{
			delete itr;
			itr = nullptr;
		}
	}
}

void Title::Draw()
{
	SetBackgroundColor(0x30, 0x30, 0x30);
	DrawFormatString(100, 300, 0xffffff, "Spaceを押すと敵を追加します");
	DrawFormatString(100, 400, 0xffffff, "敵の番号のキーを押すとダメージを与えます");
	for (int i = 0; i < enemys.size(); i++)
	{
		if (enemys[i] == nullptr)
		{
			continue;
		}
		enemys[i]->Draw(100, 500 + i * 30);
	}
	//DrawFormatString(100, 400, 0xffffff, "Press Space to Scene Change");
}
