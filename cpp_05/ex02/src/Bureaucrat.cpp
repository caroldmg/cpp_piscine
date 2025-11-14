#include "../inc/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(MIN_GRADE)
{
	std::cout << "Bureaucrat default created " << std::endl;
}

Bureaucrat::Bureaucrat(std::string name): name(name)
{
	this->grade = MIN_GRADE;
	std::cout << "Bureaucrat " << this->name << " created " << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade): name(name)
{
	if (grade < MAX_GRADE)
		throw (Bureaucrat::GradeTooHighException());
	if (grade > MIN_GRADE)
		throw (Bureaucrat::GradeTooLowException());
	this->grade = grade;
	std::cout << "Bureaucrat " << this->name << " created " << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& org) : name(org.name)
{
	*this = org;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat eliminated" << std::endl;
}

// OPERADORES

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &org)
{
	const_cast<std::string&>(this->name) = org.getName();
	if (this != &org)
	{
		this->grade = org.getGrade();
	}
	std::cout << "Copy Assigment operator called" << std::endl;
	return (*this);
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &toPrint)
{
	os << toPrint.getName() << ", bureaucrat grade " << toPrint.getGrade();
	return (os);
}

// MÉTODOS DE CLASE

std::string Bureaucrat::getName() const
{
	return (this->name);
}

int	Bureaucrat::getGrade() const
{
	return (this->grade);
}

void Bureaucrat::incrementGrade()
{
	if (this->grade == MAX_GRADE)
		throw (Bureaucrat::GradeTooHighException());
	grade--;
}

void Bureaucrat::decrementGrade()
{
	if (this->grade == MIN_GRADE)
		throw (Bureaucrat::GradeTooLowException());
	grade++;
}

void Bureaucrat::signForm(AForm& f) const
{
	if (f.getGradeToSign() < this->getGrade())
	{
		std::cout << RED << "Bureaucrat " << this->getName() << " couldn't sign " << f.getName() << " beacuse their grade is too low" << RESET << std::endl;
		return ;
	}
	if (f.getIsSigned() == true)
	{
		std::cout << YELLOW << "Bureaucrat " << this->getName() << " couldn't sign " << f.getName() << " beacuse it's already signed" << RESET << std::endl;
		return ;
	}
	f.beSigned(*this);
	std::cout << MAGENTA << "Bureaucrat " << this->getName() << " signed form " << f.getName() << RESET << std::endl;
}

void Bureaucrat::executeForm(AForm const &form) const
{
	if (form.getGradeToSign() < this->getGrade())
	{
		std::cout << RED << "Bureaucrat " << this->getName() << " couldn't execute " << form.getName() << " beacuse their grade is too low" << RESET << std::endl;
		return ;
	}
	form.execute(*this);
	std::cout << GREEN << "Bureaucrat " << this->getName() << "executed form " << form.getName() << RESET << std::endl;
}

// EXCEPTIONS

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("⚠️ GRADE TOO HIGH ⚠️");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("⚠️ GRADE TOO LOW ⚠️");
}