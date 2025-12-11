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
	for (int i = 0; i < 6; i++)
	{
		if (input == LITERALS[i])
			return (i);
	}
	return (-1);
}

type	getType(const std::string &input)
{
	if (isChar(input))
		return (CHAR);
	if (isInt(input))
		return (INT);
	if (isDouble(input))
		return (DOUBLE);
	if (isFloat(input))
		return (FLOAT);
	if (isPseudoLiteral(input))
		return (PSEUDOLIT);
	else
		return (ERROR);
}

// limits

// para los limites de int:
/*
	para los limites de int:
	- variable tipo long a la que metems el valor del input como long, y comprobamos qe no sea mayor a intMax  ni menor a intmin

	limites de float:
	- >FLOTMAX, <-FLTMAX;
	// strtod(toConvert.c_str(), &end)

	limites de double
	- >DBLMAX, <-DBLMAX;
*/

/**
 */
bool checkLimits(const std::string &input, type t)
{
	if (t == INT)
	{
		long num = strtol(input.c_str(), NULL, 10);
		if (num < INT_MIN || num > INT_MAX)
			return (false);
	}
	else if (t == FLOAT || t == DOUBLE)
	{
		double num = strtod(input.c_str(), NULL);
		
		if (t == FLOAT)
		{
			if (num < FLT_MIN || num > FLT_MAX)
				return (false);
		}
		else
		{
			if (num < DBL_MIN || num > DBL_MAX)
				return (false);
		}
	}
	return (true);
}