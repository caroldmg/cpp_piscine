/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 22:25:26 by danjimen          #+#    #+#             */
/*   Updated: 2025/10/01 17:25:34 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

#include "WrongCat.hpp"

int main()
{
	{
		std::cout << MAGENTA << std::endl << "-- ANIMALS --" << RESET << std::endl;
		const Animal* animal = new Animal();
		const Animal* dog = new Dog();
		const Animal* cat = new Cat();
		std::cout << dog->getType() << " " << std::endl;
		std::cout << cat->getType() << " " << std::endl;
		cat->makeSound(); //will output the cat sound!
		dog->makeSound(); //will output the dog sound!
		animal->makeSound(); //will output the default sound!

		delete cat;
		delete dog;
		delete animal;
	}

	{
		std::cout << MAGENTA << std::endl << "-- WRONG ANIMALS --" << RESET << std::endl;
		const WrongAnimal* wrongAnimal = new WrongAnimal();
		const WrongAnimal* wrongCat = new WrongCat();
		std::cout << wrongCat->getType() << " " << std::endl;
		wrongCat->makeSound(); //will output the default sound!
		wrongAnimal->makeSound(); //will output the default sound!

		delete wrongCat;
		delete wrongAnimal;
	}

	return 0;
}