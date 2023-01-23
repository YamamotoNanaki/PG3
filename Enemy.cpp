#include "Enemy.h"
#include "DxLib.h"
#include "Input.h"

Enemy::Enemy()
{
	phase = approach;
	status = "‹ßÚ";
}

void Enemy::Draw(int x, int y)
{
	DrawFormatString(x, y, 0xffffff, "enemy , Œ»Ý‚Ìs“® : %s", status.c_str());
}

void Enemy::Approach()
{
	if (Input::Instance()->Trigger(KEY_INPUT_SPACE))
	{
		phase = shooting;
		status = "ŽËŒ‚";
	}
}

void Enemy::Shooting()
{
	if (Input::Instance()->Trigger(KEY_INPUT_SPACE))
	{
		phase = exit;
		status = "—£’E";
	}
}

void Enemy::Exit()
{
	if (Input::Instance()->Trigger(KEY_INPUT_SPACE))
	{
		phase = approach;
		status = "‹ßÚ";
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