#pragma once

class Scene
{
public:
	virtual ~Scene() {}
	virtual void Update() = 0;
	virtual void Draw() = 0;
};

