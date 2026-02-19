#include "BitcoinExchange.hpp"

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << RED << "this program needs a file as argument" << std::endl;
		return (-1); 
	}
	try
	{
		BitcoinExchange be(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}