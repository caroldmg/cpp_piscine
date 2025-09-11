#include "Fixed.hpp"

Fixed::Fixed()
{
	this->value = 0;
	std::cout << "Default constructor called" << std::endl;
}

// darle el valor al nuevo elemento de esta manera me permite inicializar el atributo con ese valor en vez de inicialiar y reasignar;
Fixed::Fixed(const Fixed &original) : value(original.value)
{
	// this->value = original.getRawBits();
	std::cout << "Fixed copy constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "destroyer" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &original)
{
	std::cout << "Copy assignment operator called " << std::endl;
	if (this != &original)
		value = original.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->value = raw;
}
