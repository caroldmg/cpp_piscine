#include "Dog.hpp"

Dog::Dog() : Animal("dog")
{
	std::cout << "Dog default constructor called " << std::endl;
}

Dog::Dog(const Dog& org)
{
	std::cout << "Dog copy construcctor called" << std::endl;
	*this = org;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called " << std::endl;
}

Dog& Dog::operator=(const Dog &org)
{
	this->type = org.type;
	std::cout << "Dog operator '=' overload here" << std::endl;
	return(*this);
}

std::string	Dog::getType() const
{
	return (this->type);
}

void	Dog::makeSound() const
{
	std::cout << "🎤🐕 woof woof" << std::endl;
}