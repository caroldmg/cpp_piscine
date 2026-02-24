#include "RPN.hpp"

// CONSTRUCTORES Y DESTRUCTORES
RPN::RPN()
{
	throw RPN::EmptyConstructorException();
}

RPN::RPN(const RPN &org)
{
	*this = org;
}

RPN::RPN(std::string argv)
{
	if (this->isValidInput(argv) == false)
		throw RPN::InvalidInputException();
	this->calculate(argv);
	
	if (this->_data.size() != 1)
		throw RPN::InvalidInputException();
	else
		std::cout << getResult() << std::endl;
}

RPN::~RPN(){}

// OPERATORS
RPN &RPN::operator=(const RPN &org)
{
	if (this != &org)
		this->_data = org._data;
    return *this;
}

// MÉTODOS DE CLASE

bool	RPN::isValidInput(std::string argv)
{
	int	i = 0;
	int nums = 0;
	int ops = 0;
	// REVISAR QUE NO ME MANDEN NUMEROS NEGATIVOS, O SEA, DESPUES DE CADA ELEMENTO TIENE QUE HABER UN ESPACIO

	while (i < (int)argv.size())
	{
		if (isspace(argv[i]))
			return (false);
		if (isdigit(argv[i]))
		{
			nums++;
			i++;
			if (i < (int)argv.size() && isdigit(argv[i]))
				return (false);
		}
		else if (argv[i] == '+' || argv[i] == '-' || argv[i] == '*' || argv[i] == '/')
		{
			ops++;
			if (nums < 2)
				return (false);
			nums--;
			i++;
		}
		else
			return (false);
		if (i < (int)argv.size())
		{
			if (!isspace(argv[i]))
				return (false);
			i++;
		}
	}
	return (nums == 1);
}

void	RPN::operatorHandler(char op)
{
	int res;
	int a = this->_data.top();
	this->_data.pop();
	int b = this->_data.top();
	this->_data.pop();

	switch (op)
	{
		case '+':
			res = sum(a, b);
			break;
		case '-':
			res = substract(a, b);
			break;
		case '*':
			res = multiplication(a, b);
			break;
		case '/':
			res = division(a, b);
			break;
		default:
			throw RPN::InvalidInputException();
			break;
	}
	this->_data.push(res);
}

void	RPN::calculate(std::string argv)
{
	std::stringstream ss(argv);
	int	num;
	std::string element;
	while (ss >> element)
	{
		if (element.size() != 0)
			throw RPN::InvalidInputException();
		if (isdigit(element[0]))
		{
			std::stringstream(element) >> num;
			this->_data.push(num);
		}
		else
			operatorHandler(element[0]);
	}
}

int RPN::sum(int a, int b)
{
	return (b + a);
}

int RPN::substract(int a, int b)
{
	return (b - a);
}

int RPN::multiplication(int a, int b)
{
	return (b * a);
}

int RPN::division(int a, int b)
{
	if (a == 0)
		throw RPN::DivisionByZeroException();
	return (b / a);
}

int	RPN::getResult() const
{
	return (this->_data.top());
}