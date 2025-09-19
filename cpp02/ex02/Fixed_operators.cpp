#include "Fixed.hpp"

// INCREMENT / DECREMENT OPERATORS

/**
 * Como internamente ya guardamos un entero escalado,
 * para moverlo 1 ε (epsilon)(unidad minima) basta con sumar 1 a value
 */

/// @brief incrementa en 1ε
/// @return devuelve la referencia al mismo objeto
// ++a
Fixed& Fixed::operator++()
{
	this->value += 1;
	return (*this);
}

/// @brief Guarda una copia del objeto original, incrementa, y devuelve la copia
/// @return devuelve el estado antes del incremento
// a++
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

/**
 *Al multiplicar dos valores escalados la escala se duplica 
 *  para evitar esto, hacemos shift a la derecha después de multiplicar
 **/

Fixed Fixed::operator*(const Fixed& toOperate) const
{
	Fixed res;

	res.value = (this->value * toOperate.value) >> fractionalBits;
	return (res);
}

/**
 * Antes de dividir tenemos que hacer un shift a la izquierda par mantener la escala
 * basicamente, si dividimos dos numeros con la misma escala pues perdemos esa escala, y al hacer ese shift al numerador estamos momentaneamente doblando la escala para no perderla
 * */

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
	// esto deberia ser posible usando el >
	// pero no se si se puede sin usar namespaces
	// https://cplusplus.com/reference/utility/rel_ops/ 
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
	// std::cout << "Copy assignment operator called " << std::endl;
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
