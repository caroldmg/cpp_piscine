#include "Dog.hpp"

Dog::Dog() : Animal("dog")
{
	std::cout << "Dog default constructor called " << std::endl;
	this->brain = new Brain();
}

Dog::Dog(const Dog& org)
{
	std::cout << "Dog copy construcctor called" << std::endl;
	this->brain = NULL;
	*this = org;
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << "Dog destructor called " << std::endl;
}

Dog& Dog::operator=(const Dog &org)
{
	std::cout << "Dog operator '=' overload here" << std::endl;
	if (this != &org)
	{
		this->type = org.type;
		if (this->brain)
			delete this->brain;
		this->brain = new Brain(*org.brain);
	}
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

void	Dog::setIdea(int i, std::string& idea)
{
	brain->setIdea(i, idea);
}

std::string	Dog::getIdea(int i)
{
	return (brain->getIdea(i));
}