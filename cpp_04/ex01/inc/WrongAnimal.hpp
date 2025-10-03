#pragma once
#include "iostream"

class WrongAnimal
{
	protected:
		std::string type;
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal& org);
		WrongAnimal(std::string type);
		~WrongAnimal();

		WrongAnimal&	operator=(const WrongAnimal &org);

		std::string		getType() const;
		void	makeSound() const;
};
