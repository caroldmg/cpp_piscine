#include "Intern.hpp"

// CONSTRUCTOR AND DESTRUCTOR

Intern::Intern()
{
	std::cout << "default intern cnstructor called " << std::endl;
}

Intern::Intern(const Intern &org)
{
	std::cout << "intern copy constructor called " << std::endl;
	*this = org;
}

Intern::~Intern()
{
	std::cout << "Intern destructor " << std::endl;
}

// OPERATORS

Intern& Intern::operator=( const Intern& org)
{
	std::cout << "Copy Intern Assigment operator called" << std::endl;
	if (this != &org)
		*this = org;
	return (*this);
}

// MEMBER FUNCTIONS

AForm* Intern::makeForm(std::string form, std::string target)
{
	if (form.empty() || target.empty())
	{
		std::cout << RED << "Empty parameters" << RESET << std::endl;
		return (NULL);
	}
	std::string types[3] = {
		"presidential", 
		"robotomy",
		"shrubbery"
	};
	int f;
	std::string write;
	for (int i = 0; i < 3; i++)
	{
		if (types[i] == form)
			f = i;
	}
	switch (f)
	{
		case 0:
		{
			write = "Presidential Pardon Form";
			return (new PresidentialPardonForm(target));
		}
		case 1:
		{
			write = "Robotomy Request Form";
			return (new RobotomyRequestForm(target));
		}
		case 2:
		{
			write = "Shrubbery Creation Form";
			return (new ShrubberyCreationForm(target));
		}
		default:
			throw (std::runtime_error("Invalid type of form"));
	}

	std::cout << "Intern creates " << write << std::endl;
}