#include "Rectangle.h"
#include <iostream>

void Rectangle::size()
{
	area = base * height;
}

void Rectangle::draw()
{
	std::cout << "Rectangle area :" << area << std::endl << std::endl;
}

void Rectangle::SetBase(float base)
{
	this->base = base;
	std::cout << "Set base :" << base << std::endl << std::endl;
}

void Rectangle::SetHeight(float height)
{
	this->height = height;
	std::cout << "Set height :" << height << std::endl << std::endl;
}
