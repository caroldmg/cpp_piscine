#include "Fixed.hpp"

// CONSTRUCTORES

Fixed::Fixed()
{
	this->value = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &original) : value(original.value)
{
	// this->value = original.getRawBits();
	std::cout << "Fixed copy constructor called" << std::endl;
}

Fixed::Fixed(const int intNum)
{
	value = intNum << this->fractionalBits;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float floatNum)
{ 
	std::cout << "Float constructor called" << std::endl;
	this->value = (int)roundf(floatNum * (1 << Fixed::fractionalBits));
}

// DESTRUCTOR

Fixed::~Fixed()
{
	std::cout << "destroyer" << std::endl;
}


// MÉTODOS DE CLASE

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

float	Fixed::toFloat() const
{
	float newValue;

	newValue = ((float)this->value / ( 1 << Fixed::fractionalBits));
	return (newValue);
}

int		Fixed::toInt(void) const
{
	int newValue;

	newValue = value >> this->fractionalBits;
	return (newValue);
}

// OPERATORS

Fixed &Fixed::operator=(const Fixed &original)
{
	std::cout << "Copy assignment operator called " << std::endl;
	if (this != &original)
		value = original.getRawBits();
	return (*this);
}

std::ostream& operator<<(std::ostream &os, const Fixed &toPrint)
{
	os << toPrint.toFloat();
	return (os);
}