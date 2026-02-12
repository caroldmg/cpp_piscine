#include "BitcoinExchange.hpp"

// CONSTRUCTORES Y DESTRUCTOR
BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& org)
{
	*this = org;
	// ¿un iterador para copiar todo el map de uno a otro?
	
}
BitcoinExchange::~BitcoinExchange(){}

// OPERADORES
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange& org)
{
	if (this != &org)
	{
		// ¿iterador para copiar todo el mapa?
	}
}

// MEMBER FUNCTIONS

bool	BitcoinExchange::dataInit(std::ifstream &data)
{

}

int	BitcoinExchange::readFile(std::string infile)
{
	std::ifstream f;
	std::ifstream df;
	f.open(infile);
	df.open("./data.csv");
	if (!f.is_open() || df.is_open())
	{
		std::cerr << RED << "Error: could not open file" << std::endl;
		return (-1);
	}
	this->dataInit(df);
}