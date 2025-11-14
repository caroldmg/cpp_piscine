#include "../inc/RobotomyRequestForm.hpp"

//CONSTRUCTORES Y DESTRUCTORES 

RobotomyRequestForm::RobotomyRequestForm(): AForm("Robotomy Request Form", 72, 45), target("something")
{
	std::cout << "RobotomyRequestForm default constructor called " << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("Robotomy Request Form", 72, 45), target(target)
{
	std::cout << "RobotomyRequestForm parameter constructor called " << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &org):  AForm("Robotomy Request Form", 72, 45), target(org.target)
{
	std::cout << "RobotomyRequestForm copy constructor called " << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called " << std::endl;
}

// OPERADORES

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& org)
{
	if (this != &org)
		*this = org;
	return (*this);
}

// MÉTODOS DE CLASE

std::string RobotomyRequestForm::getTarget() const
{
	return (this->target);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	
	int num = rand() % 100;

	if (this->getGradeToExec() < executor.getGrade())
		throw(AForm::GradeTooLowException());

	std::cout << "** DRILLING NOISES **" << std::endl;
	if (num % 2 == 0)
		std::cout << GREEN << "Target " << this->getTarget() << " has been robotomized succesfully. 🤖" << RESET << std::endl;
	else
		std::cout << RED << this->getTarget() << "'s robotomy has failed ⚙︎ " << RESET << std::endl;
}
