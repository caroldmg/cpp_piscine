#pragma once
#include <iostream>

class Brain
{
	private: //¿protected?
		std::string ideas[100];
	public:
		Brain();
		Brain(const Brain& org);
		virtual ~Brain();

		Brain&	operator=(const Brain &org);

		void		setIdea(int i, std::string idea);
		std::string	getIdea(int i);
};