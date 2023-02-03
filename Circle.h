#pragma once
#include "IShape.h"
class Circle : public IShape
{
private:
    float radius;
public:
    void size()override;
    void draw()override;
    void SetRadius(float radius);
};

