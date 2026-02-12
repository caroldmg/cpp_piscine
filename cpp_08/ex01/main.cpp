#include "Span.hpp"

int main()
 {
	srand(time(NULL));
	{
		std::cout << GREEN << " ---- TRY 1:numeros añadidos manualmente ---- \n"<< RESET << std::endl;
		try
		{
			Span sp = Span(5);
			
			sp.addNumber(6);
			sp.addNumber(3);
			sp.addNumber(17);
			sp.addNumber(9);
			sp.addNumber(11);
			
		 
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;

		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
	}

	{

		try
		{
			std::cout << GREEN << " ---- TRY 2: span de 10 000 números ----\n" << RESET << std::endl;
		 
			Span newSpan = Span(10000);
			newSpan.fillSpan(1, 10001);
			std::cout << newSpan.shortestSpan() << std::endl;
			std::cout << newSpan.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
	}

	{
		std::cout << GREEN  << "---- TRY 3: span de 50 numeros aleatorios ----\n" << RESET  << std::endl;

		try
		{
			Span newSpan = Span(50);
			newSpan.fillSpan(1, 10001);
			std::cout << newSpan.shortestSpan() << std::endl;
			std::cout << newSpan.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
	}
	{
		std::cout << GREEN  << "---- TRY 4: span imposible porque no hay numeros ----\n" << RESET << std::endl;

		try
		{
			Span newSpan = Span(50);
			std::cout << newSpan.shortestSpan() << std::endl;
			std::cout << newSpan.longestSpan() << std::endl;

		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
	}
	{
		std::cout << GREEN << " ---- TRY 5: span imposible porque solo hay un numero ----\n" << RESET << std::endl;

		try
		{
			Span newSpan = Span(50);
			newSpan.addNumber(596);
			std::cout << newSpan.shortestSpan() << std::endl;
			std::cout << newSpan.longestSpan() << std::endl;

		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
	}
	{
		std::cout << GREEN << "---- TRY 6: limite de numeros ---- \n" << RESET << std::endl;

		try
		{
			Span newSpan = Span(2);
			newSpan.addNumber(596);
			newSpan.addNumber(5);
			newSpan.addNumber(9);
			std::cout << newSpan.shortestSpan() << std::endl;
			std::cout << newSpan.longestSpan() << std::endl;

		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
	}

	return (0);
}

/* int main(void)
{
	std::cout << GREEN "------------ TEST ADDNUMBER ----------------" << RESET << std::endl;
	Span sp1 = Span(5);
	try
	{
		sp1.addNumber(6);
		sp1.addNumber(5);
		sp1.addNumber(17);
		sp1.addNumber(9);
		sp1.addNumber(11);
		sp1.addNumber(42);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << sp1.shortestSpan() << std::endl;
		std::cout << sp1.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	//---------------------------------------------------------------------------------------------------------------------
	std::cout << GREEN "------------ TEST NÚMEROS ALEATORIOS ----------------" << RESET << std::endl;
	Span sp2 = Span(10000);
	try
	{
		srand(time(0));
		for (size_t i = 0; i < 10000; i++)
		{
				int r = rand() % 500000;
				sp2.addNumber(r);
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << sp2.shortestSpan() << std::endl;
		std::cout << sp2.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	//---------------------------------------------------------------------------------------------------------------------
	std::cout << GREEN "------------ TEST RANGO DE NÚMEROS ----------------" <<  RESET << std::endl;
	Span sp3 = Span(5);
	try
	{
		sp3.fillSpan(1, 100);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << sp3.shortestSpan() << std::endl;
		std::cout << sp3.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
 */