#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	// std::cout << "Ice constructor called "  << std::endl;
}

// comoIce hereda de AMateria, llama al constructor de copia de esta clase. Si tuviera elementos propios los inicializaría aqui tambien
Ice::Ice(const Ice& org) : AMateria(org)
{
	// std::cout << "Ice copy constructor called" << std::endl;
}

Ice::~Ice()
{
	// std::cout << "Ice destructor called" << std::endl;
}

Ice& Ice::operator=(const Ice& org)
{
	// std::cout << "Ice Assignation operator called" << std::endl;
	if (this != &org)
		*this = org;
	return (*this);
}

AMateria*  Ice::clone() const
{
	AMateria *mat = new Ice();
	return (mat);
}
void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() <<" *" << std::endl;
}