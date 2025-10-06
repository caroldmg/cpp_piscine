/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 22:25:26 by danjimen          #+#    #+#             */
/*   Updated: 2025/10/06 12:07:02 by cde-migu         ###   ########.fr       */
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
		
		std::cout << GREEN <<  "\t--- Animal sounds ---" << RESET << std::endl;
		

		for (int i = 0; i < SIZE; i++)
			animals[i]->makeSound();
		
		std::cout << RED <<  "\t --- Animal killing ---" << RESET << std::endl;

		for (int i = 0; i < SIZE; i++)
			delete animals[i];
	}
	{
		std::cout << BLUE << "\t---- TEST IDEAS ----" << std::endl;
		
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
		
	}
	
	return 0;
}