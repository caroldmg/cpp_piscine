#pragma once

#define BLACK   "\033[1m\033[30m"
#define RED     "\033[1m\033[31m"
#define GREEN   "\033[1m\033[32m"
#define YELLOW  "\033[1m\033[33m"
#define BLUE    "\033[1m\033[34m"
#define MAGENTA "\033[1m\033[35m"
#define CYAN    "\033[1m\033[36m"
#define RESET   "\033[0m"

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
		void	readFile(std::ifstream &infile);
		bool	dataInit(std::ifstream &data);

		// funciones de validacion y cálculo deberían ser privadas no?

	public:
		BitcoinExchange(/* args */);
		BitcoinExchange(const std::string infile);
		BitcoinExchange(const BitcoinExchange &org);
		~BitcoinExchange();

		BitcoinExchange &operator=(const BitcoinExchange &org);

		// excepciones
};




