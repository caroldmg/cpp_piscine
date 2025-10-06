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

class AAnimal
{
	protected:
		std::string type;
	public:
		AAnimal();
		AAnimal(const AAnimal& org);
		AAnimal(std::string type);
		virtual ~AAnimal();

		AAnimal&	operator=(const AAnimal &org);

		std::string		getType() const;
		virtual void	makeSound() const = 0;
		/*
			para hacer la clase abstracta tengo que tener una funcion que se iguale a 0, y esta funcion no puede ser definida.
			Las clases que heredan de una clase abstracta son también abstractas a no ser que se sobreescriban todas las funciones virtuales de esta clase
		 */
};
