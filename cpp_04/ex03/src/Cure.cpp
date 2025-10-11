#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << "cure default constructor here"  << std::endl;
}

Cure::Cure(const Cure& org): AMateria(org)
{
		std::cout << "Cure Assignation operator called" << std::endl;
}

Cure::~Cure()
{
	std::cout << "Cure destructor called "  << std::endl;
}

Cure& Cure::operator=(const Cure& org)
{
	std::cout << "Cure Assignation operator called" << std::endl;
	if (this != &org)
		*this = org;
	return (*this);
}

AMateria  *Cure:: clone() const
{
	AMateria *mat = new Cure();
	return (mat);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << " 's wound *"  << std::endl;
}