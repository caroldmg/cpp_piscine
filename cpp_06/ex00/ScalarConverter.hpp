#pragma once
#include <iostream>
#include <string>
#include <climits>
#include <cfloat>

enum type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	PSEUDOLIT,
	ERROR
};

#define LITERALS { "-inff", "+inff", "nanf", "-inf", "+inf", "nan" }

class ScalarConverter
{
	private:
	// si hago que el constructor sea privado consigo que la clase no pueda ser instanciada
		ScalarConverter();
		ScalarConverter(const ScalarConverter& org);
		~ScalarConverter();
		ScalarConverter& operator=(const ScalarConverter& org);

	public:
		static void convert(std::string input);

		class InvalidInputException : public std::exception
		{
			virtual const char *what() const throw();
		};
};

bool isChar(std::string input);
bool isInt(std::string input);
bool isFloat(std::string input);
bool isDouble(std::string input);
type	getType(const std::string &input);