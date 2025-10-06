#include "Cat.hpp"

Cat::Cat() : Animal("cat")
{
	std::cout << "Cat default constructor called " << std::endl;
	this->brain = new Brain();
}

Cat::Cat(const Cat& org)
{
	std::cout << "Cat copy construcctor called" << std::endl;
	this->brain = NULL;
	*this = org;
}

Cat::~Cat()
{
	delete this->brain;
	std::cout << "Cat destructor called " << std::endl;
}

// if (this != &org) es necesario para evitar borrar el cerebro en caso de hacer cat1 = cat1;
// eliminar el cerebro es necesario para, en caso de tener un valor original, no tener leaks
Cat& Cat::operator=(const Cat &org)
{
	std::cout << "Cat operator '=' overload here" << std::endl;
	if (this != &org)
	{
		this->type = org.type;
		if (this->brain)
			delete this->brain;
		this->brain = new Brain(*org.brain);
	}
	return (*this);
}

std::string	Cat::getType() const
{
	return (this->type);
}

void Cat::makeSound() const
{
	std::cout << "🎤🐈‍ meooooow" << std::endl;
}

void Cat::setIdea(int i, std::string& idea)
{
	if (brain)
		brain->setIdea(i, idea);
}

std::string Cat::getIdea(int i)
{
	if (!brain)
		return "no ideas found";
	return (brain->getIdea(i));
}