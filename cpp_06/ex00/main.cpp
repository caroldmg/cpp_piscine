#include "ScalarConverter.hpp"

int main (int argc, char **argv)
{
	if(argc != 2)
	{
		std::cerr << RED << "ERROR: Uso incorrecto. \n Prueba a introducir: " << argv[0] << " y el parámetro a convertir" << RESET << std::endl;
		return (1);
	}
	try
	{
		ScalarConverter::convert(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}