#include "Circle.h"
#include <iostream>

void Circle::size()
{
	area = radius * radius * 3.141592653589793f;
}

void Circle::draw()
{
	std::cout << "Circle area :" << area << std::endl << std::endl;
}

void Circle::SetRadius(float radius)
{
	this->radius = radius;
	std::cout << "Set radius :" << radius << std::endl << std::endl;
}
