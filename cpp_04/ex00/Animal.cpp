#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal default constructor called " << std::endl;
	this->type = "duck";
}

Animal::Animal(const Animal& org)
{
	std::cout << "Animal copy construcctor called" << std::endl;
	*this = org;
}

Animal::Animal(std::string type)
{
	std::cout << "animal construcctor called" << std::endl;
	this->type = type;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called " << std::endl;
}

Animal& Animal::operator=(const Animal &org)
{
	this->type = org.type;
	std::cout << "Animal operator '=' overload here" << std::endl;
	return(*this);
}

std::string Animal::getType() const
{
	return (this->type);
}

void	Animal::makeSound() const
{
	std::cout << " 🎤🦆 quack quack quack" << std::endl;
}