#include "ScalarConverter.hpp"

// CONSTRUCTORES Y DESTRUCTOR

ScalarConverter::ScalarConverter()
{
	std::cout << "default constructor called " << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& org)
{
	std::cout << "copy constructor called " << std::endl;
	*this = org;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "destructor called " << std::endl;
}

// OPERATORS

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& org)
{
	std::cout << "SC assigment operator called" << std::endl;
	(void)org;
	return (*this);
}

// CLASS METHODS

void	ScalarConverter::convert(std::string input)
{
	type t;

	if (input.empty())
		throw (ScalarConverter::InvalidInputException());
	type = getType(input);

}

// EXCEPTIONS

const char *ScalarConverter::InvalidInputException::what() const throw()
{
	return ("Invalid Input");
}
