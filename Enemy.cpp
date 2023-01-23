#include "Enemy.h"
#include "DxLib.h"
#include "Input.h"

Enemy::Enemy()
{
	phase = approach;
	status = "�ߐ�";
}

void Enemy::Draw(int x, int y)
{
	DrawFormatString(x, y, 0xffffff, "enemy , ���݂̍s�� : %s", status.c_str());
}

void Enemy::Approach()
{
	if (Input::Instance()->Trigger(KEY_INPUT_SPACE))
	{
		phase = shooting;
		status = "�ˌ�";
	}
}

void Enemy::Shooting()
{
	if (Input::Instance()->Trigger(KEY_INPUT_SPACE))
	{
		phase = exit;
		status = "���E";
	}
}

void Enemy::Exit()
{
	if (Input::Instance()->Trigger(KEY_INPUT_SPACE))
	{
		phase = approach;
		status = "�ߐ�";
	}
}

Enemy::~Enemy()
{
}

void Enemy::Update()
{
	(this->*func[phase])();
}

void (Enemy::* Enemy::func[])() =
{
	&Enemy::Approach,
	&Enemy::Shooting,
	&Enemy::Exit
};