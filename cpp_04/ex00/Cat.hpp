#pragma once
#include "Animal.hpp"

class Cat: public Animal
{
	public:
		Cat();
		Cat(const Cat& org);
		~Cat();

		Cat&	operator=(const Cat &org);

		std::string	getType() const;
		void		makeSound() const;
};
