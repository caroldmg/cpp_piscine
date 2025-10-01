#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal default constructor called " << std::endl;
	this->type = "duck";
}

WrongAnimal::WrongAnimal(const WrongAnimal& org)
{
	std::cout << "WrongAnimal copy construcctor called" << std::endl;
	*this = org;
}

WrongAnimal::WrongAnimal(std::string type)
{
	std::cout << "WrongAnimal construcctor called" << std::endl;
	this->type = type;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called " << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &org)
{
	this->type = org.type;
	std::cout << "WrongAnimal operator '=' overload here" << std::endl;
	return(*this);
}

std::string WrongAnimal::getType() const
{
	return (this->type);
}

void	WrongAnimal::makeSound() const
{
	std::cout << " 🎤🦆 quack quack quack" << std::endl;
}