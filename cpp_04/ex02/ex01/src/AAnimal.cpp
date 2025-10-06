#include "AAnimal.hpp"

AAnimal::AAnimal()
{
	std::cout << "AAnimal default constructor called " << std::endl;
	this->type = "duck";
}

AAnimal::AAnimal(const AAnimal& org)
{
	std::cout << "AAnimal copy construcctor called" << std::endl;
	*this = org;
}

AAnimal::AAnimal(std::string type)
{
	std::cout << "AAnimal construcctor called" << std::endl;
	this->type = type;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called " << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal &org)
{
	this->type = org.type;
	std::cout << "AAnimal operator '=' overload here" << std::endl;
	return(*this);
}

std::string AAnimal::getType() const
{
	return (this->type);
}

void	AAnimal::makeSound() const
{
	std::cout << " 🎤🦆 quack quack quack" << std::endl;
}
