#pragma once

class IShape
{
protected:
	float area = 0;
public:
	virtual void size() = 0;
	virtual void draw() = 0;
};

