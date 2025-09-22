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
		~Fixed();

		Fixed& operator=(const Fixed &original);

		int		getRawBits() const;
		void	setRawBits(int const raw);
};