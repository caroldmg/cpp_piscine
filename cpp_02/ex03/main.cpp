#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

int main( void )
{
	Point	a(0, 0);
	Point	b(4, 0);
	Point	c(0, 3);

	Point	point(2, 0);
	Point	point2(5, 5);
	Point	point3(1, 1);

	std::cout << "In a border: " << bsp(a, b, c, point) << std::endl;
	std::cout << "Outside: "<< bsp(a, b, c, point2) << std::endl;
	std::cout << "Inside: " << bsp(a, b, c, point3) << std::endl;

	return 0;
}
