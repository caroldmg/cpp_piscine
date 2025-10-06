

#pragma once
#include <iostream>

#define BLACK   "\033[1m\033[30m"
#define RED     "\033[1m\033[31m"
#define GREEN   "\033[1m\033[32m"
#define YELLOW  "\033[1m\033[33m"
#define BLUE    "\033[1m\033[34m"
#define MAGENTA "\033[1m\033[35m"
#define CYAN    "\033[1m\033[36m"
#define RESET   "\033[0m"

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
