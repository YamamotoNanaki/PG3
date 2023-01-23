#pragma once
#include "Scene.h"
#include "Enemy.h"

class Title : public Scene
{
	Enemy enemy;
public:
	void Update();
	void Draw();
};

