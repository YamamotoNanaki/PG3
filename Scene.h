#pragma once

class Scene
{
protected:
	bool key;
	bool oldkey;
public:
	virtual ~Scene() {}
	virtual void Update() = 0;
	virtual void Draw() = 0;
};

