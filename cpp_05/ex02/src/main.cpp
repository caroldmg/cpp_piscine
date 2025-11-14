
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	try
	{
		Bureaucrat	b2("b2", 1);
		AForm *pardon =   new PresidentialPardonForm("pardon");

		b2.executeForm(*pardon);
		b2.signForm(*pardon);
		b2.signForm(*pardon);
		b2.executeForm(*pardon);
		delete pardon;

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\n";

	try
	{
		Bureaucrat	b3("b3", 1);
		AForm *robot = new RobotomyRequestForm("robot");

		b3.executeForm(*robot);
		b3.signForm(*robot);
		b3.signForm(*robot);
		b3.executeForm(*robot);
		delete robot;

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\n";

	try
	{
		Bureaucrat	b4("b4", 1);
		AForm *tree = new ShrubberyCreationForm("tree");

		b4.executeForm(*tree);
		b4.signForm(*tree);
		b4.signForm(*tree);
		b4.executeForm(*tree);
		delete tree;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}