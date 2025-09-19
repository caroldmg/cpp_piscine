#include "Fixed.hpp"

int main()
{
	Fixed a;
	Fixed b(10);
	Fixed c(10.42f);
	Fixed d(b);

	std::cout << "DEFAULT CONSTRUCTOR --> a =" << a << std::endl;
	std::cout << "INT CONSTRUCTOR --> b =" << b << std::endl;
	std::cout << "FLOAT CONSTRUCTOR --> c =" << c << std::endl;
	std::cout << "COPY CONSTRUCTOR --> d =" << d << std::endl;

	std::cout << "---Conversión ---" << std::endl;
	std::cout << "a as int: " << a.toInt() << std::endl;
	std::cout << "c as int: " << c.toInt() << std::endl;
	std::cout << "b as float: " << b.toFloat() << std::endl;


	std::cout << "---OPERADORES ---" << std::endl;
	a = Fixed(123.456f);
	std::cout << "a = " << a << " (assigned from float 123.456f)" << std::endl;


    Fixed x(5.5f);
    Fixed y(2);
	std::cout << "---Aritmética ---" << std::endl;
    std::cout << "x = " << x << ", y = " << y << std::endl;
    std::cout << "x + y = " << (x + y) << std::endl;
    std::cout << "x - y = " << (x - y) << std::endl;
    std::cout << "x * y = " << (x * y) << std::endl;
    std::cout << "x / y = " << (x / y) << std::endl;

	std::cout << "---Comparaciones ---" << std::endl;
    std::cout << "x > y: "  << (x > y) << std::endl;
    std::cout << "x < y: "  << (x < y) << std::endl;
    std::cout << "x == y: " << (x == y) << std::endl;
    std::cout << "x != y: " << (x != y) << std::endl;

	Fixed z(0);
    std::cout << "z = " << z << std::endl;
    std::cout << "++z = " << ++z << " (preincrement)" << std::endl;
    std::cout << "z++ = " << z++ << " (postincrement, prints old value)" << std::endl;
    std::cout << "z after postincrement = " << z << std::endl;
    std::cout << "--z = " << --z << " (predecrement)" << std::endl;
    std::cout << "z-- = " << z-- << " (postdecrement)" << std::endl;
    std::cout << "z after postdecrement = " << z << std::endl;


    Fixed e(3.5f);
    Fixed f(7.25f);
    const Fixed g(2.2f);
    const Fixed h(9.9f);

    std::cout << "min(e, f) = " << Fixed::min(e, f) << std::endl;
    std::cout << "max(e, f) = " << Fixed::max(e, f) << std::endl;
    std::cout << "min(g, h) = " << Fixed::min(g, h) << std::endl;
    std::cout << "max(g, h) = " << Fixed::max(g, h) << std::endl;


	return (0);
}