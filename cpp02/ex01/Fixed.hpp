#pragma once
#include <iostream>

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
		int		toInt(void) const;
};

std::ostream& operator<<(std::ostream &os, const Fixed &toPrint);