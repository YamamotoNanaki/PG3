#pragma once
#include <string>

class Enemy
{
private:
	size_t phase;
	std::string status;

	enum PhaseInfo
	{
		approach, shooting, exit
	};

public:
	Enemy();
	~Enemy();
	void Update();
	void Draw(int x, int y);
	void Approach();
	void Shooting();
	void Exit();

private:
	static void (Enemy::* func[])();
};

