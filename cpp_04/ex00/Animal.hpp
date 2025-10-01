

#pragma once
#include <iostream>

#define MAGENTA "\033[35m"
#define RESET "\033[0m"

class Animal
{
	protected:
		std::string type;
	public:
		Animal();
		Animal(const Animal& org);
		Animal(std::string type);
		virtual ~Animal();

		Animal&	operator=(const Animal &org);

		std::string		getType() const;
		virtual void	makeSound() const;
};
