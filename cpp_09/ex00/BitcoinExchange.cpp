#include "BitcoinExchange.hpp"

// CONSTRUCTORES Y DESTRUCTOR
BitcoinExchange::BitcoinExchange()
{
	throw BitcoinExchange::EmptyConstructorException();
}

BitcoinExchange::BitcoinExchange(const std::string file)
{
	try
	{
		this->readFile(file);	
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& org)
{
	if (this != &org)
		*this = org;
	// ¿un iterador para copiar todo el map de uno a otro?
}
BitcoinExchange::~BitcoinExchange(){}

// OPERADORES
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange& org)
{
	if (this != &org)
	{
		this->_data = org._data;
	}
	return (*this);
}

// MEMBER FUNCTIONS

bool	checkDate(std::string date)
{
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return (false);
	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5,6).c_str());
	int day = std::atoi(date.substr(8,9).c_str());


	if (year >= 1990 && year <= 9999)
	{
		if (month >= 1 && month <= 12)
		{
			if (day > 31)
				return (false);
			else if ((day >= 1 && day <= 31) && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12))
				return (true);
			else if ((day >= 1 && day <= 30) && (month == 4 || month == 6 || month == 9 || month == 11))
				return (true);
			else if ((day >= 1 && day <= 28) && month == 2)
				return (true);
			else if (day == 29 && month == 2 && ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)))
				return (true);
		}
		else
			return (false);
	}
	return (false);
}

bool checkValue(float val)
{
	if (val < 0)
	{
		std::cout << RED << NOT_POSITIVE_ERROR << RESET << std::endl;
		return (false);
	}
	else if (val > 1000)
	{
		std::cout << RED << LARGE_NUM_ERROR << RESET << std::endl;
		return (false);
	}
	return (true);
}

float	BitcoinExchange::calcValue(std::string date, float value)
{
	std::map<std::string, float>::iterator	it;
	float									res = 0;

	it = this->_data.upper_bound(date);	
	if (it == this->_data.begin())
	{
		std::cout << RED << NOT_INFO << RESET << std::endl;
		return (-1);
	}
	else
		--it;
	if (it != this->_data.end())
		res = value * it->second;
	return (res);

}

void	BitcoinExchange::print(std::string date, float value)
{
	float res = this->calcValue(date, value);
	if (res < 0)
		return;
	std::stringstream ss;
	ss << value;
	std::string vals = ss.str(); 

	std::cout << date << " => " 
			<<  vals << " = ";
	std::cout << std::setprecision(2)
			<< std::fixed 
			<< res << std::endl;
	std::cout.unsetf(std::ios::fixed);
}

bool	BitcoinExchange::parseInput(std::string date, float val)
{
	if (checkDate(date) == false)
	{
		std::cerr << RED << WRONG_DATE_ERROR << RESET << std::endl;
		return (false);
	}
	if (checkValue(val) == false)
	{
		return (false);
	}
	return (true);
}

void	BitcoinExchange::parseData(std::string date, float val)
{
	if (checkDate(date) == false)
		throw std::runtime_error(RED WRONG_DATE_ERROR RESET);
	if (val < 0)
		throw std::runtime_error(RED NOT_POSITIVE_ERROR RESET);
}

/**
 * introducir en el map los pares de clave:valor de los datos
 * que leemos en el archivo .csv
 * primero leo la linea, asigno a cada elemento su valor:
 * a date la parte de delante de la coma, a value, la parte posterior (convertida en float)
 */
bool	BitcoinExchange::dataInit(std::ifstream &data)
{
	std::string line;
	std::string date;
	std::string str_val;
	float		floatval;
	
	std::getline(data, line);

	while (std::getline(data, line))
	{
		date.insert(0, line, 0, line.find(','));
		str_val.insert(0, line, (line.find(',') + 1), line.size());
		if (std::atof(str_val.c_str()) == 0 && str_val != "0")
			throw std::runtime_error( RED "Error: not a valid value" RESET);
		floatval = std::atof(str_val.c_str());
		this->parseData(date, floatval);
		this->_data[date] = floatval;
		date.clear();
		str_val.clear();
	}
	return true;
}

void	BitcoinExchange::manageInput(std::ifstream &file)
{
	std::string line;
	std::string date;
	std::string str_val;
	float		floatval;

	while(std::getline(file, line))
	{
		if (line.empty())
			continue;
		date.insert(0, line, 0, (line.find('|') - 1));
		str_val.insert(0, line, (line.find('|') + 1), line.size());
		floatval = std::atof(str_val.c_str());

		if (this->parseInput(date, floatval) == true)
			this->print(date, floatval);
		date.clear();
		str_val.clear();
	}
}

bool	BitcoinExchange::readFile(std::string infile)
{
	std::ifstream file;
	std::ifstream datafile;
	file.open(infile.c_str());
	datafile.open("./data.csv");
	if (!file.is_open() || !datafile.is_open())
	{
		throw BitcoinExchange::OpenFileErrorException();
		datafile.close();
		file.close();
		return (false);
	}
	try
	{
		this->dataInit(datafile);
		this->manageInput(file);
		return (true);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (false);
	}
	
}
