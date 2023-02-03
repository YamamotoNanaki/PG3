#include "Circle.h"
#include "Rectangle.h"
#include <cstdlib>

void main()
{
	IShape* shape1;
	IShape* shape2;

	shape1 = new Circle;
	shape2 = new Rectangle;

	Circle* c = dynamic_cast<Circle*>(shape1);
	Rectangle* r = dynamic_cast<Rectangle*>(shape2);

	if (c)
	{
		c->SetRadius(3);
	}
	if (r)
	{
		r->SetBase(4);
		r->SetHeight(5);
	}

	shape1->size();
	shape2->size();

	shape1->draw();
	shape2->draw();

	delete shape1;
	delete shape2;

	system("PAUSE");
}