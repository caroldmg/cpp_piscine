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
	{
		// std::cout << date << "size --> " << date.size() << std::endl;
		// std::cout << "heckdate etorna al rpincipio del to" << std::endl;
		return (false);
	}
	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5,6).c_str());
	int day = std::atoi(date.substr(8,9).c_str());


	if (year >= 1990 && year <= 9999)
	{
		// TODO: revisar que parte devuelve false
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
		std::cout << NOT_POSITIVE_ERROR << std::endl;
		return (false);
	}
	else if (val > 1000)
	{
		std::cout << LARGE_NUM_ERROR << std::endl;
		return (false);
	}
	return (true);
}

bool	BitcoinExchange::parseData(std::string date, float value)
{
	if (checkDate(date) == false)
	{
		std::cerr << WRONG_DATE_ERROR << std::endl;
		return (false);
	}
	if (checkValue(value) == false)
		return (false);
	return (true);
}

/**
 * introducir en el map los pares de clave:valor de los datos
 * que leemos en el archivo .csv
 * primero leo la linea, asigno a cada elemento su valor:
 * a date la parte de delante de la coma, a value, la parte posterior (convertida en float)
 */
bool	BitcoinExchange::dataInit(std::ifstream &data)
{
	// aqui deberia iniciar el map y pasarle los valores del archivo .csv
	std::string line;
	std::string date;
	std::string str_val;
	float		floatval;
	
	std::getline(data, line);

	while (std::getline(data, line))
	{
		// primero paso a key su valor, o sea, la parte anterior a la coma
		// str1.insert(pos, str2, str_idx, str_num);
		date.insert(0, line, 0, line.find(','));
		str_val.insert(0, line, (line.find(',') + 1), line.size());
		floatval = std::atof(str_val.c_str());
		if (this->parseData(date, floatval) == false)
			return false;
		// this->parseData(date, floatval);
		this->_data[date] = floatval;
		date.clear();
		str_val.clear();
	}
	return true;
}

bool	BitcoinExchange::readFile(std::string infile)
{
	std::ifstream f;
	std::ifstream df;
	f.open(infile.c_str());
	df.open("./data.csv");
	if (!f.is_open() || !df.is_open())
	{
		throw BitcoinExchange::OpenFileErrorException();
		df.close();
		f.close();
		// std::cerr << RED << "Error: could not open file" << std::endl;
		return (false);
	}
	try
	{
		this->dataInit(df);
		AHORA MISMO TENGO HECHO LA INICIALIZACION (PARSEO), Y ME FALTARIA LA APRTE DE ACEPTAR EL INPUT (LEER QUE LA FECHA Y TAL SEA CORRECTA) Y HACER EL CALCULO, QUE NO SERÁ GRAN COSA DIGO YO?
		return (true);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (false);
	}
	
	// parser
}