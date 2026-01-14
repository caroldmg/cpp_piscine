#include "iter.hpp"

int main()
{
	std::string	words[] = {"tu", "puta", "madre", "pringao"};
	int			numbers[] = {1, 2, 3, 4};
	const int 		wlen = sizeof(words) / sizeof(words[0]);

	{
		std::cout << "-----------> 1" << std::endl;
		iter(words, wlen, printWithLove);
	}
	{	
		std::cout << "-----------> 2" << std::endl;
		std::cout << "antes:" << std::endl;
		iter(words, wlen, printStr);
		iter(words, wlen, rotOne);
		std::cout << "despues:" << std::endl;
		iter(words, wlen, printStr);
	}
	{
		std::cout << "-----------> 3" << std::endl;
		std::cout << "antes:" << std::endl;
		iter(numbers, 4, printInt);
		iter(numbers, 4, triple);
		std::cout << "despues:" << std::endl;
		iter(numbers, 4, printInt);
	}
}