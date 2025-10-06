#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Default brain construcctor called" << std::endl;
}

Brain::Brain(const Brain& org)
{
	std::cout << "Brain copy construcctor called" << std::endl;
	*this = org;
}

Brain::~Brain()
{
	std::cout << "Brain default destructor called" << std::endl;
}

Brain& Brain::operator=(const Brain &org)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = org.ideas[i];
	return (*this);
}

void		Brain::setIdea(int i, std::string idea)
{
	this->ideas[i] = idea;
}

std::string Brain::getIdea(int i)
{
	return (this->ideas[i]);
}