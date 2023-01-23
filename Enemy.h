#pragma once

class Enemy
{
private:
	unsigned int hp = 3;
	static bool deathFlag;
	static unsigned int enemyNum;
	unsigned int number = 0;

public:
	Enemy();
	~Enemy();
	void Damage();
	void Draw(int x, int y);
	static bool GetDeathFlag();
};

