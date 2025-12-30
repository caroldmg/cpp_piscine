#include "ScalarConverter.hpp"


void	printPseudoLit(const std::string &input, int i)
{
	std::cout << "char: impossible " << std::endl;
	std::cout << "int: impossible " << std::endl;
	if (i < 3)
	{
		if (input == literals[i])
		{
			std::cout << "float: " << input << std::endl;
			std::cout << "double: " << input.substr(0, input.length() -1) << std::endl;
			return ;
		}
	}
	else if (i >= 3)
	{
		if (input == literals[i])
		{
			std::cout << "float: " << input << "f" << std::endl;
			std::cout << "double: " << input << std::endl;
			return ;
		}
	}
}

void	printChar(const std::string &input)
{
	char c = input[0];
	if (isprint(c))
		std::cout << "char: '"  << c << "'" << std::endl;
	else
		std::cout << "char: non displayable " << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

// printint
void	printInt(const std::string &input)
{
	double	db = strtod(input.c_str(), NULL);
	int		nb = strtol(input.c_str(), NULL, 10);

	if (nb >= ' ' && nb <= '~' && std::isprint(static_cast<unsigned char>(nb)))
		std::cout << "char: '" << static_cast<char>(nb) << "'" << std::endl;
	else
		std::cout << "char: Non displayable " << std::endl;
	std::cout << "int: " << nb << std::endl;
	std::cout << "float: " << db << ".0f" << std::endl;
	std::cout << "double: " << db << ".0" << std::endl;
}

void	printFt(const std::string &input)
{
	double	db = strtod(input.c_str(), NULL);
	int		nb = static_cast<int>(db);
	float	ft = static_cast<float>(db);

	if (nb >= ' ' && nb <= '~' && std::isprint(static_cast<unsigned char>(nb)))
		std::cout << "char: '" << static_cast<char>(nb) << "'" << std::endl;
	else
		std::cout << "char: Non displayable " << std::endl;
	std::cout << "int: " << nb << std::endl;
	std::cout<< std::fixed << std::setprecision(1); 
	std::cout << "float: " << ft <<  "f\n"; //std::fixed?
	std::cout << "double: " << db << std::endl;
}

void	printNum(const std::string &input, type t)
{
	switch (t)
	{
		case CHAR:
			printChar(input);
			break;
		case INT:
			printInt(input);
			break;
		case FLOAT:
		case DOUBLE:
			printFt(input);
			break;
		default:
			throw ScalarConverter::InvalidInputException();
			break;
	}
}
