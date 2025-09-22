#pragma once
#include <iostream>
#include <cmath>


/* 
	Cómo se guarda el número

Usando 8 bits fraccionales (fractionalBits = 8).

Eso significa que 1 unidad real equivale a 2^8 = 256 en la representación interna.

Ejemplo:

El número 5 se guarda como 5 << 8 = 1280.

El número 3.5 se guarda como 3.5 * 256 = 896 (aproximando si hago constructor desde float).
*/
class Fixed
{
	private:
		int	value;
		static const int fractionalBits = 8;
	public:
		Fixed();
		Fixed(const Fixed &original);
		Fixed(const int intNum);
		Fixed(const float floatNum);
		~Fixed();

		Fixed& operator=(const Fixed &original);

		int		getRawBits() const;
		void	setRawBits(int const raw);
		float	toFloat() const;
		int		toInt() const;
};

std::ostream& operator<<(std::ostream &os, const Fixed &toPrint);