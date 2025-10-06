/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 22:25:26 by danjimen          #+#    #+#             */
/*   Updated: 2025/10/06 13:01:57 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

#define SIZE 20

int main()
{
	{
		Animal* animals[SIZE];
	
		std::cout << BLUE <<  "\t--- Animal creation ---" << RESET << std::endl;
		
		for (int i = 0; i < SIZE; i++)
		{
			if (i < SIZE/2)
				animals[i] = new Dog();
			else
				animals[i] = new Cat();
		}
		std::cout << std::endl;

		
		std::cout << GREEN <<  "\t--- Animal sounds ---" << RESET << std::endl;
		

		for (int i = 0; i < SIZE; i++)
			animals[i]->makeSound();
		std::cout << std::endl;

		std::cout << RED <<  "\t --- Animal killing ---" << RESET << std::endl;

		for (int i = 0; i < SIZE; i++)
			delete animals[i];
		std::cout << std::endl;
		std::cout << std::endl;
		
	}
	{
		std::cout << BLUE << "\t---- TEST IDEAS GATUNAS----" << std::endl;
		
		Cat manila;
		std::string idea1 = "quiero atún";

		for (int i = 0; i < 100; i++)
			manila.setIdea(i, idea1);
		
		std::cout << GREEN << "Lo que piensa Manila: " << RESET << manila.getIdea(42) << std::endl;
		
		Cat copyCat1(manila);
		Cat copyCat2;

		std::cout << MAGENTA << "Lo que piensa copyCat1: " << RESET << copyCat1.getIdea(42) << std::endl;
		std::cout << RED << "Lo que piensa copyCat2: " << RESET << copyCat2.getIdea(42) << std::endl;
		
		copyCat2 = manila;
		std::cout << YELLOW << "Lo que piensa copyCat2: " << RESET << copyCat2.getIdea(42) << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		
	}
	{
		std::cout << BLUE << "\t---- TEST IDEAS PERRUNAS ----" << std::endl;
		
		Dog toby;
		std::string idea1 = "quiero huesitos";

		for (int i = 0; i < 100; i++)
			toby.setIdea(i, idea1);
		std::cout << GREEN << "Lo que piensa Toby: " << RESET << toby.getIdea(42) << std::endl;
		
		Dog copyDog1(toby);
		Dog copyDog2;

		std::cout << MAGENTA << "Lo que piensa copyDog1: " << RESET << copyDog1.getIdea(42) << std::endl;
		std::cout << RED << "Lo que piensa copyDog2: " << RESET << copyDog2.getIdea(42) << std::endl;
		
		copyDog2 = toby;
		std::cout << YELLOW << "Lo que piensa copyDog2: " << RESET << copyDog2.getIdea(42) << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		
	}
	{
		std::cout << MAGENTA << "El main que propone el subject" << RESET << std::endl;
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		
		delete j;//should not create a leak
		delete i;
	}
	
	return 0;
}