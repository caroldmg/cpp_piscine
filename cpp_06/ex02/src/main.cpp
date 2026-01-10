#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


// srand() generates a 'seed' for rand() to generate a pseudo random number with the value seed. This should only be seeded once, beffore any calls to rand() and at the start of the program 
int main()
{
	srand(time(NULL));
	{
		std::cout << BLUE << "\t 1. Comprobar que funciona identify " << RESET << std::endl;

		A	*a = new A();
		B	*b = new B();
		C	*c = new C();

		identify(a);
		identify(b);
		identify(c);
		identify(NULL);

		identify(*a);
		identify(*b);
		identify(*c);

		delete a;
		delete b;
		delete c;
	}
	{
		std::cout << BLUE << "\t 2. Generar elementos aleatoriamente, comprobar después de qué tipo son" << RESET << std::endl;
		Base	*base;
		
		base = generate();
		
		identify(base);
		identify(*base);

		delete base;
	}
}