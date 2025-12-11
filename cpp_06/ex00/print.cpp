#include "ScalarConverter.hpp"

void	printChar(const std::string &input)
{
	char c = input[0];
	if (isprint(c))
		std::cout << "char: '"  << c << "'" << std::endl;
	else
		std::cout << "char: non displayable " << std::endl;
	// TODO: continuar esto
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void	printPseudoLit(const std::string &input)
{
	// solo deberia entrar a esta funcion si previamente nos hemos asegurado de que verdaderamente es un pseudolit
	std::cout << "char: impossible " << std::endl;
	std::cout << "int: impossible " << std::endl;
	for (int i = 0; i < 3; i++)
	{
		if (input == LITERALS[i])
		{
			std::cout << "float: " << input << std::endl;
			std::cout << "double: " << input.substr(0, input.length() -1) << std::endl;
			return ;
		}
	}
	for (int i = 3; i < 6; i++)
	{
		if (input == LITERALS[i])
		{
			std::cout << "float: " << input << "f" << std::endl;
			std::cout << "double: " << input << std::endl;
			return ;
		}
	}
}

// printint
// printfloat
// printdouble
