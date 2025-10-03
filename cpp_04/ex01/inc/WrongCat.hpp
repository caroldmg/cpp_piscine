#pragma once
#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(const WrongCat& org);
		~WrongCat();

		WrongCat&	operator=(const WrongCat &org);

		std::string	getType() const;
		void		makeSound() const;
};
