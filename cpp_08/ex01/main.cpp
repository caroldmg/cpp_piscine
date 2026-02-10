#include "Span.hpp"

int main()
{
	srand(time(NULL));
	{
		Span sp = Span(5);
		
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		
		std::cout << "TRY 1" << std::endl;
	 
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	{
		std::cout << "TRY 2" << std::endl;
	
		Span newSpan = Span(10001);
		newSpan.fillSpan(1, 10001);
		std::cout << newSpan.shortestSpan() << std::endl;
		std::cout << newSpan.longestSpan() << std::endl;
	}

	{
		std::cout << "TRY 3" << std::endl;
	
		Span newSpan = Span(50);
		newSpan.fillSpan(1, 10001);
		std::cout << newSpan.shortestSpan() << std::endl;
		std::cout << newSpan.longestSpan() << std::endl;
	}

	return (0);
}