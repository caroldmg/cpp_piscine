#include "Point.hpp"

Point::Point(): x(0), y(0)
{
	//	std::cout << "Point constructor" << std::endl;
}

Point::Point(const float x, const float y): x(x), y(y)
{
	//	std::cout << "Point constructor from floats" << std::endl;
}

Point::~Point()
{
	//	std::cout << "Point destructor" << std::endl;
}
Point::Point(const Point& original): x(original.x), y(original.y)
{}

// CLASS METHODS

Fixed Point::getX() const
{
	return (this->x);
}

Fixed Point::getY() const
{
	return (this->y);
}

// OPERATORS

Point& Point::operator=(const Point &original)
{
	if (this != &original)
	{
		(Fixed)this->x = original.getX();
		(Fixed)this->y = original.getY();
	}
	return (*this);
}