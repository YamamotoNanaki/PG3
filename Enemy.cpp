#include "Enemy.h"
#include "DxLib.h"

bool Enemy::deathFlag = false;
unsigned int Enemy::enemyNum = 0;


void Enemy::Damage()
{
	hp--;
	if (hp == 0)
	{
		deathFlag = true;
	}
}

Enemy::Enemy()
{
	if (deathFlag)
	{
		deathFlag = false;
	}
	number = enemyNum;
	enemyNum++;
}

bool Enemy::GetDeathFlag()
{
	return deathFlag;
}

void Enemy::Draw(int x, int y)
{
	DrawFormatString(x, y, 0xffffff, "enemy%d , hp : %d", number, hp);
}

Enemy::~Enemy()
{
	enemyNum--;
}
