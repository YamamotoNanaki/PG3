#pragma once
#include "IShape.h"
class Rectangle : public IShape
{
	float base = 1.f;
	float height = 1.f;
public:
	void size()override;
	void draw()override;
	void SetBase(float base);
	void SetHeight(float height);
};

