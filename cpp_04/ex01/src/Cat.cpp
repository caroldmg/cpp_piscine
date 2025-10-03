#include "Cat.hpp"

Cat::Cat() : Animal("cat")
{
	std::cout << "Cat default constructor called " << std::endl;
}

Cat::Cat(const Cat& org)
{
	std::cout << "Cat copy construcctor called" << std::endl;
	*this = org;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called " << std::endl;
}

Cat& Cat::operator=(const Cat &org)
{
	this->type = org.type;
	std::cout << "Cat operator '=' overload here" << std::endl;
	return(*this);
}

std::string	Cat::getType() const
{
	return (this->type);
}

void Cat::makeSound() const
{
	std::cout << "🎤🐈‍ meooooow" << std::endl;
}

void Cat::setIdea(int i, std::string )
{
	brain.setIdea
}