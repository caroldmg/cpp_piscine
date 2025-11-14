#include "../inc/ShrubberyCreationForm.hpp"

//CONSTRUCTORES Y DESTRUCTORES 

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("Shrubbery Creation Form", 145, 137), target("something")
{
	std::cout << "ShrubberyCreationForm default constructor called " << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("Shrubbery Creation Form", 145, 137), target(target)
{
	std::cout << "ShrubberyCreationForm parameter constructor called " << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &org): AForm("Shrubbery Creation Form", 145, 137), target(org.target)
{
	std::cout << "ShrubberyCreationForm copy constructor called " << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called " << std::endl;
}

// OPERADORES

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& org)
{
	if (this != &org)
		*this = org;
	return (*this);
}

// MÉTODOS DE CLASE

std::string ShrubberyCreationForm::getTarget() const
{
	return (this->target);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	std::string fileName = this->getTarget() + "_shrubbery"; 
	std::ofstream newFile(fileName.c_str());

    if (this->getGradeToExec() < executor.getGrade())
        throw(AForm::GradeTooLowException());

    if (!newFile.is_open())
        throw(std::runtime_error("ShrubberyCreationForm: can't create file " + fileName));

    newFile << "               ,@@@@@@@,\n"
               "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
               "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n"
               "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n"
               "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n"
               "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n"
               "   `&%\\ ` /%&'    |.|        \\ '|8'\n"
               "       |o|        | |         | |\n"
               "       |.|        | |         | |\n"
               "jgs \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_\n" << std::endl;

    newFile.close();

    std::cout << "Check out for some cool trees in file " << fileName << std::endl;
}

