#include "Fixed.hpp"

// CONSTRUCTORES

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


/**
 * The '<<' operator shifts to the left (this equals to multiplying for 2^fractionalBits)
 */
Fixed::Fixed(const int intNum)
{
// convert to the corresponding fixed point value
	value = intNum << this->fractionalBits;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float floatNum)
{
	// convert to the corresponding fixed point value 
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

// converts the fixed-point valu to a floating-point value
/**
 * we cast to float before the division to make sure the operation is done in floating, so it preserves the decimal part
 */
float	Fixed::toFloat() const
{
	float newValue;

	newValue = ((float)this->value / ( 1 << Fixed::fractionalBits));
	return (newValue);
}

// Converts the fixed-point value to an integer value
// The '>>' operator shifts to the right (this equals to divide for 2^fractionalBits)
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