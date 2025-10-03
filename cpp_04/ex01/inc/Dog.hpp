#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal
{
	private:
		Brain *brain;
	public:
		Dog();
		Dog(const Dog& org);
		~Dog();

		Dog&	operator=(const Dog &org);

		std::string	getType() const;
		void		makeSound() const;
		void		setIdea(int i, std::string& idea);
		std::string getIdea(int i);
};