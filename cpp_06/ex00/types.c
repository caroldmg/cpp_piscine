#include "ScalarConverter.hpp"

bool isChar(std::string input)
{
	// ¿se refiere que tiene que ser alfabetico, o a que sea un tipo char? porque un char puede ser un numero tambien pero nose
	// igual se refeire a printable character???
    return (std::isalpha(input[0]) && input.length() == 1); 
}

bool isInt(std::string input)
{
	int i = 0;
	if (input[i] == '-' || input[i] == '+')
		i++;
	while (i < input.length())
	{
		if (std::isdigit(input[i]) == false)
			return (false);
		i++;
	}
	return (true);
}

bool isFloat(std::string input)
{
	int i = 0;
	int point = 0;

	if (input == "-inff" || input == "+inff" || input == "nanf")
		return true;

	if (input[input.length() - 1] != 'f' || input.length() == 2 && !isdigit(input[0]))
		return (false);

	if (input[i] == '-' || input[i] == '+')
		i++;

	while (i < input.length())
	{
		if (std::isdigit(input[i]) == false && input[i] != '.')
			return (false);
		if (input[i] == '.')
			point++;
		if (point > 1)
			return (false);
		i++;
	}
	return (true);
}

bool isDouble(std::string input)
{
	int i = 0;
	int point = 0;

	if (input == "-inf" || input == "+inf" || input == "nan")
		return true;

	if (input[i] == '-' || input[i] == '+')
		i++;

	while (i < input.length())
	{
		if (std::isdigit(input[i]) == false && input[i] != '.')
			return (false);
		if (input[i] == '.')
			point++;
		if (point > 1)
			return (false);
		i++;
	}
	return (true);
}

/**
 * @brief Checks if the input is one of the pseudoliterals the subject precises
 * 
 *
 * @param input The input string.
 * @return if the input is a pseudo literal, it will return the position in the literals string,
 * it will return -1 if it's not in the array
 */
int isPseudoLiteral(std::string input)
{
	std::string literals[6] = {
		"-inff",
		"+inff",
		"nanf",
		"-inf",
		"+inf",
		"nan"
	};
	for (int i = 0; i < 6; i++)
	{
		if (input == literals[i])
			return (i);
	}
	return (-1);
}
