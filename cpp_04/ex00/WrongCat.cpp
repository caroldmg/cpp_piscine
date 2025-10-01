#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat default constructor called " << std::endl;
}

WrongCat::WrongCat(const WrongCat& org)
{
	std::cout << "WrongCat copy construcctor called" << std::endl;
	*this = org;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called " << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat &org)
{
	this->type = org.type;
	std::cout << "WrongCat operator '=' overload here" << std::endl;
	return(*this);
}

std::string	WrongCat::getType() const
{
	return (this->type);
}

void WrongCat::makeSound() const
{
	std::cout << "🎤🐈‍⬛ meooooow" << std::endl;
}