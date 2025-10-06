#pragma once
#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog: public AAnimal
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