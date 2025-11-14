
#include "Intern.hpp"

int main(void)
{
	Intern test_intern;

	std::cout << std::endl << "Creating Forms" << std::endl;
	AForm	*presi = NULL;
	AForm	*robotomy = NULL;
	AForm	*shrubbery = NULL;

	try
	{
		presi = test_intern.makeForm("presidential", "Andres Manuel");
		robotomy = test_intern.makeForm("robotomy", "c3po");
		shrubbery = test_intern.makeForm("shrubbery creation", "forest");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	Bureaucrat	boss("Boss", 1);

	if (presi)
		boss.executeForm(*presi);
	if (robotomy)
	boss.executeForm(*robotomy);
	if (shrubbery)
		boss.executeForm(*shrubbery);
	
	delete presi;
	delete robotomy;
	delete shrubbery;
}