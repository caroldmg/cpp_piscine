#include "ScalarConverter.hpp"

void	printChar(const std::string &input)
{
	char c = input[0];
	if (isprint(c))
		std::cout << "char: '"  << c << "'" << std::endl;
	else
		std::cout << "char: non displayable " << std::endl;
	// TODO: continuar esto
}