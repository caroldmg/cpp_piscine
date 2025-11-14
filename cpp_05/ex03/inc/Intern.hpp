#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern &org);
		~Intern();

		Intern& operator=(const Intern &org);

		AForm* makeForm(std::string form, std::string target);

};