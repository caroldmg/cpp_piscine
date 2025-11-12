#include "Bureaucrat.hpp"

int main()
{
	{
		// creacion de burocratas

		Bureaucrat *b1 = new Bureaucrat();
		Bureaucrat b2("antonio");
		Bureaucrat b3("maripili", 75);
		std::cout << "holaaa" << std::endl;
		Bureaucrat b4(b2);

		std::cout << "----\n" << *b1 << "----\n" << std::endl;
		std::cout << "----\n" << b2 << "----\n" << std::endl;
		std::cout << "----\n" << b3 << "----\n" << std::endl;
		std::cout << "----\n" << b4 << "----\n" << std::endl;
	}
	{
		// excepciones en la creacion de burócratas
		std::cout << " ---- ERRORES CREACION DE BUROCRATAS ---- " << std::endl;
		try
		{
			Bureaucrat b5("malo", 0);
		} catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

		try
		{
			Bureaucrat b6("peor", 151);
		} catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		// errores de incremento y decremento
		std::cout << " ---- ERRORES INCREMENTO Y DCREMENTO ---- " << std::endl;
		try
		{
			Bureaucrat b7("bobo", 150);
			std::cout << b7 << std::endl;
			b7.incrementGrade();
			std::cout << "Increment: " << b7 << std::endl;
			b7.decrementGrade();
			std::cout << "Decrement: " << b7 << std::endl;
			b7.decrementGrade();
			std::cout << "Decrement: " << b7 << std::endl;
		} catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

		try
		{
			Bureaucrat b8("estupido", 1);
			std::cout << b8 << std::endl;
			b8.decrementGrade();
			std::cout << "Decrement: " << b8 << std::endl;
			b8.incrementGrade();
			std::cout << "Increment: " << b8 << std::endl;
			b8.incrementGrade();
			std::cout << "Increment: " << b8 << std::endl;
		} catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}
