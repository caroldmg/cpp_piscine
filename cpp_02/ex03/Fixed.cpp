#include "Fixed.hpp"

// CONSTRUCTORES

Fixed::Fixed()
{
	this->value = 0;
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &original) : value(original.value)
{
	// this->value = original.getRawBits();
	// std::cout << "Fixed copy constructor called" << std::endl;
}

Fixed::Fixed(const int intNum)
{
	value = intNum << this->fractionalBits;
	// std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float floatNum)
{ 
	// std::cout << "Float constructor called" << std::endl;
	this->value = (int)roundf(floatNum * (1 << Fixed::fractionalBits));
}

// DESTRUCTOR

Fixed::~Fixed()
{
	// std::cout << "destroyer" << std::endl;
}

// MÉTODOS DE CLASE

int	Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

void Fixed::setRawBits(int const raw)
{
	// std::cout << "setRawBits member function called" << std::endl;
	this->value = raw;
}

float	Fixed::toFloat() const
{
	float newValue;

	newValue = ((float)this->value / (1 << Fixed::fractionalBits));
	return (newValue);
}

int		Fixed::toInt(void) const
{
	int newValue;

	newValue = value >> this->fractionalBits;
	return (newValue);
}

Fixed& Fixed::min(Fixed& num1, Fixed& num2)
{
	if (num1 < num2)
		return (num1);
	return (num2);
}

const Fixed& Fixed::min(const Fixed& num1, const Fixed& num2)
{
	if (num1 < num2)
		return (num1);
	return (num2);
}

Fixed& Fixed::max(Fixed& num1, Fixed& num2)
{
	if (num1 > num2)
		return (num1);
	return (num2);
}

const Fixed& Fixed::max(const Fixed& num1, const Fixed& num2)
{
	if (num1 > num2)
		return (num1);
	return (num2);
}
