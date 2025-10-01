#pragma once
#include "Animal.hpp"

class Dog: public Animal
{
	public:
		Dog();
		Dog(const Dog& org);
		~Dog();

		Dog&	operator=(const Dog &org);

		std::string	getType() const;
		void		makeSound() const;
};