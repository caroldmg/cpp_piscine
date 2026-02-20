#pragma once

#define BLACK   "\033[1m\033[30m"
#define RED     "\033[1m\033[31m"
#define GREEN   "\033[1m\033[32m"
#define YELLOW  "\033[1m\033[33m"
#define BLUE    "\033[1m\033[34m"
#define MAGENTA "\033[1m\033[35m"
#define CYAN    "\033[1m\033[36m"
#define RESET   "\033[0m"

#define NOT_POSITIVE_ERROR "Error: not a positive number."
#define FILE_OPEN_ERROR "Error: could not open file."
#define INPUT_ERROR "Error: bad input "
#define LARGE_NUM_ERROR "Error: too large a number"
#define WRONG_DATE_ERROR "Error: wrong date. Format should be: YYYY-MM-DD"

#include <iostream>
#include <map>
#include <string>
#include <limits.h>
#include <fstream>
#include <algorithm>

class BitcoinExchange
{
	private:
		std::map<std::string, float> _data;
		bool	readFile(std::string infile);
		bool	dataInit(std::ifstream &data);
		bool	parseData(std::string date, float val);

		// funciones de validacion y cálculo deberían ser privadas no?

	public:
		BitcoinExchange();
		BitcoinExchange(const std::string infile);
		BitcoinExchange(const BitcoinExchange &org);
		~BitcoinExchange();

		BitcoinExchange &operator=(const BitcoinExchange &org);

		// excepciones ¿hacen falta todad? mejor mensajes de error y ya
		class OpenFileErrorException : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return "error opening file";
				}
		};

		class EmptyConstructorException : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return "Error: file needed";
				}
		};

		class BadInputException : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return "Error: input not valid";
				}
		};
		class BadDateFormatException : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return "Error: wrong date. Format should be: YYYY-MM-DD";
				}
		};
		class BadValueFormatException : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return "Error: value should be a float or integer between 0-1000";
				}
		};
};

