#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << BLUE << "Error: wrong number of arguments" << std::endl;
		return (1);
	}
	try
	{
		RPN rpn(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}