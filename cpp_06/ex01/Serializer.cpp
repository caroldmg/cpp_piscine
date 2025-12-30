#include "Serializer.hpp"

// CONSTRUCTORES Y DESTRUCTOR

Serializer::Serializer()
{
	std::cout << "default constructor called " << std::endl;
}

Serializer::Serializer(const Serializer& org)
{
	std::cout << "copy constructor called " << std::endl;
	*this = org;
}

Serializer::~Serializer()
{
	std::cout << "destructor called " << std::endl;
}

// OPERATORS

Serializer& Serializer::operator=(const Serializer& org)
{
	std::cout << "Serializer assigment operator called" << std::endl;
	(void)org;
	return (*this);
}

//CLASS METHODS

uintptr_t	Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}


Data*	Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}