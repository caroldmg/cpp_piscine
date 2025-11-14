#include "../inc/PresidentialPardonForm.hpp"

//CONSTRUCTORES Y DESTRUCTORES 

PresidentialPardonForm::PresidentialPardonForm(): AForm("Presidental Pardon Form", 25, 5), target("something")
{
	std::cout << "PresidentialPardonForm default constructor called " << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("Presidental Pardon Form", 25, 5), target(target)
{
	std::cout << "PresidentialPardonForm parameter constructor called " << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &org):  AForm("Presidental Pardon Form", 25, 5), target(org.target)
{
	std::cout << "PresidentialPardonForm copy constructor called " << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor called " << std::endl;
}

// OPERADORES

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& org)
{
	if (this != &org)
		*this = org;
	return (*this);
}

// MÉTODOS DE CLASE

std::string PresidentialPardonForm::getTarget() const
{
	return (this->target);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	std::cout << GREEN << executor.getName() << " informs that " << this->getTarget() << " has been pardoned by Zaphood Beeblebrox." << RESET << std::endl;
}
