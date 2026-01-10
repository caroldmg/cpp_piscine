#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base()
{
	std::cout << "Base destructor here!" << std::endl;
}

// other methods

/**
 * Randomly instantiates A, B or C.
 * 
 * uses rand() initialized in main with srand(time(NULL)) to generate a random number
 * 
 * returns the instance as a Base pointer
 */
Base	*generate()
{
	int num = rand() % 3;

	switch (num)
	{
		case 0:
			return (new A());
		case 1:
			return (new B());
		case 2:
			return (new C());
		default:
			return (NULL);
	}
}

/**
 * Prints the actual type of the object pointed by p
 */
void	identify(Base* p)
{
	std::cout << MAGENTA << "identify ptr >>> " << RESET << std::endl;
	if (dynamic_cast<A*>(p))
	{
		std::cout << "objeto de clase derivada A 🐝" << std::endl;
		return ;
	}
	else if (dynamic_cast<B*>(p))
	{
		std::cout << "objeto de clase derivada B 🐳" << std::endl;
		return ;
	}
	else if (dynamic_cast<C*>(p))
	{
		std::cout << "objeto de clase derivada C 🐰" << std::endl;
		return ;
	}
	std::cout << RED << "puntero no válido" << std::endl;
}

/**
 * Prints the actual type referenced by p
 * here we have to use the try catch because in case dynamic cast fails and the type is a reference type, it throws an exception
 */
void	identify(Base& p)
{
	std::cout << GREEN << "identify reference >>> " << RESET << std::endl;
	try
	{
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "objeto de clase derivada A 🐝" << std::endl;
		return ;
	} catch(const std::exception& e){}
	try
	{
		B& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "objeto de clase derivada B 🐳" << std::endl;
		return ;
	} catch(const std::exception& e){}
	try
	{
		C& c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "objeto de clase derivada C 🐰" << std::endl;
		return ;
	} catch(const std::exception& e){}
	std::cout << RED << "no es objeto de clase derivada A, B o C" << std::endl;
}