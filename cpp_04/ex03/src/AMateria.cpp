#include "AMateria.hpp"

AMateria::AMateria()
{
	// std::cout << "Abstract Materia constructor called " << std::endl;
}

// el constructor de copia no usa el operador = sino que inicialia los atrobutos(type) al mismo valor que original
AMateria::AMateria(const AMateria& org) : type(org.type)
{
	// std::cout << "Constructor de copia de AMateria" << std::endl;
}

AMateria::AMateria(std::string const & type)
{
	this->type = type;
}

AMateria::~AMateria()
{
	// std::cout << "Abstract Materia destructor called" << std::endl;
}

AMateria& AMateria::operator=(const AMateria &org)
{
	if (this != &org)
		this->type = org.getType();
	// std::cout << "sobrecarga de operador = " << std::endl;
	return (*this);
}


std::string const & AMateria::getType() const
{
	return (this->type);
}


void AMateria::use(ICharacter& target)
{
	std::cout << "this materia does nothing to " << target.getName() << std::endl;
}