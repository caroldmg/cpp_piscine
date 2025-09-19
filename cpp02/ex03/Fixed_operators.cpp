#include "Fixed.hpp"

// INCREMENT / DECREMENT OPERATORS

Fixed& Fixed::operator++()
{
	this->value += 1;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	
	this->value +=1;
	return (temp);
}

Fixed& Fixed::operator--()
{
	this->value -= 1;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);

	this->value -=1;
	return (temp);
}

// ARITHMETIC OPERATORS

Fixed	Fixed::operator+(const Fixed& toOperate) const
{
	Fixed res;
	res.value = this->value + toOperate.value;
	return (res);
}

Fixed Fixed::operator-(const Fixed& toOperate) const
{
	Fixed res;
	res.value = this->value - toOperate.value;
	return (res);
}

Fixed Fixed::operator*(const Fixed& toOperate) const
{
	Fixed res;

	res.value = (this->value * toOperate.value) >> fractionalBits;
	return (res);
}

Fixed Fixed::operator/(const Fixed& toOperate) const
{
	Fixed res;

	res.value = (this->value << fractionalBits) / toOperate.value;
	return (res);
}

// COMPARISON OPERATORS

bool Fixed::operator>(const Fixed& toCompare) const
{
	return (this->value > toCompare.value);
}

bool Fixed::operator<(const Fixed& toCompare) const
{
	return (toCompare.value > this->value);
}

bool Fixed::operator>=(const Fixed& toCompare) const
{
	return (this->value >= toCompare.value);
}

bool Fixed::operator<=(const Fixed& toCompare) const
{
	return (toCompare.value >= this->value);
}

bool Fixed::operator==(const Fixed& toCompare) const
{
	return (this->value == toCompare.value);
}

bool Fixed::operator!=(const Fixed& toCompare) const
{
	return !(this->value == toCompare.value);
}

// COPY ASSIGNMENT OPERATOR

Fixed &Fixed::operator=(const Fixed &original)
{
	if (this != &original)
	value = original.getRawBits();
	return (*this);
}

// INSERTION OPERATOR

std::ostream& operator<<(std::ostream &os, const Fixed &toPrint)
{
	os << toPrint.toFloat();
	return (os);
}
