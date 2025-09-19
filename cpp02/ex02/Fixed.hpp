#pragma once
#include <iostream>
#include <cmath>

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

		Fixed&	operator++(void); /* preIncrement */
		Fixed	operator++(int);
		Fixed&	operator--(void); /* preDecrement */
		Fixed	operator--(int);

		Fixed	operator+(const Fixed& toOperate) const;
		Fixed	operator-(const Fixed& toOperate) const;
		Fixed	operator*(const Fixed& toOperate) const;
		Fixed	operator/(const Fixed& toOperate) const;

		bool	operator>(const Fixed& toCompare) const;
		bool	operator<(const Fixed& toCompare) const;
		bool	operator>=(const Fixed& toCompare) const;
		bool	operator<=(const Fixed& toCompare) const;
		bool	operator==(const Fixed& toCompare) const;
		bool	operator!=(const Fixed& toCompare) const;

		static Fixed&	min(Fixed& num1, Fixed& num2);
		static const Fixed&	min(const Fixed& num1, const Fixed& num2);
		static Fixed&	max(Fixed& num1, Fixed& num2);
		static const Fixed&	max(const Fixed& num1, const Fixed& num2);

		Fixed& operator=(const Fixed &original);
		int		getRawBits() const;
		void	setRawBits(int const raw);
		float	toFloat() const;
		int		toInt() const;
};

std::ostream& operator<<(std::ostream &os, const Fixed &toPrint);