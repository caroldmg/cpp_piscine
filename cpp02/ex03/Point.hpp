#pragma once
#include "Fixed.hpp"

class Point
{
	private:
		const Fixed x;
		const Fixed y;
	public:
		Point();
		Point(const float x, const float y);
		Point(const Point& original);
		~Point();

		Point& operator=(const Point &original);
		Fixed getY() const;
		Fixed getX() const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);