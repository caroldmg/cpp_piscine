#pragma once
#include "AAnimal.hpp"
#include "Brain.hpp"


class Cat: public AAnimal
{
	private:
		Brain *brain;
	public:
		Cat();
		Cat(const Cat& org);
		~Cat();

		Cat&	operator=(const Cat &org);

		std::string	getType() const;
		void		makeSound() const;
		void		setIdea(int i, std::string& idea);
		std::string getIdea(int i);
};
