#pragma once
#include "Scene.h"
#include "Enemy.h"
#include <array>

class Title : public Scene
{
	std::array<Enemy*, 10> enemys = { nullptr };
public:
	void Update();
	void Draw();
};

