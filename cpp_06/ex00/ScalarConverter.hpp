#pragma once
#include <iostream>
#include <string>
#include <climits>
#include <cfloat>
#include <iomanip>
#include <stdlib.h>


#define RED	"\033[31m"
#define RESET "\033[0m"

enum type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	PSEUDOLIT,
	ERROR
};

// declaracion de una constante que se define en ScalarConverter.cpp
extern const std::string	literals[6];

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

bool checkLimits(const std::string &input, type t);
bool isChar(std::string input);
bool isInt(std::string input);
bool isFloat(std::string input);
bool isDouble(std::string input);
int isPseudoLiteral(std::string input);
type	getType(const std::string &input);
// print functions
void	printFt(const std::string &input);
void	printInt(const std::string &input);
void	printChar(const std::string &input);
void	printPseudoLit(const std::string &input, int i);
void	printNum(const std::string &input, type t);
