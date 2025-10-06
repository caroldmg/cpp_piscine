/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-migu <cde-migu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 22:25:26 by danjimen          #+#    #+#             */
/*   Updated: 2025/10/06 15:27:12 by cde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

#define SIZE 6

int main()
{
/*Animal animal1;
	Animal	*animal2 = new Animal();

	(void)animal2;*/
	{
		const Animal* j = new Dog();
		const Animal* i = new Cat();
	
		std::cout << "\n";
	
		delete j;//should not create a leak
		delete i;
	
		std::cout << "\n";
	}

	{
		Animal* animals[SIZE];
	
		for (size_t i = 0; i < SIZE; i++)
		{
			if (i < SIZE / 2)
				animals[i] = new Dog();
			else
				animals[i] = new Cat();
		}
	
		std::cout << "\n";
		
		for (size_t i = 0; i < SIZE; i++)
			delete animals[i];
		std::cout << "\n";
	}

	{
		Cat cat;
		Cat new_cat = cat;
		std::string idea = "miauu";
	
		for (int i = 0; i < SIZE; i++)
		{
			std::cout << cat.getIdea(i) << std::endl;
		}
	
		new_cat.setIdea(0, idea);
	
		std::cout << cat.getIdea(0) << std::endl;
	}
	return 0;
}