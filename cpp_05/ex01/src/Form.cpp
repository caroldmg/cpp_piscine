#include "Form.hpp"

// constructores y destructores
Form::Form(): name("default"), gradeToSign(MIN_GRADE), gradeToExec(MIN_GRADE), isSigned(false)
{
	std::cout << "default form constructor" << std::endl;
}

Form::Form(std::string name, int gradeToSign, int gradeToExec): name(name), gradeToSign(gradeToSign), gradeToExec(gradeToExec), isSigned(false)
{
	if (gradeToSign < MAX_GRADE || gradeToExec < MAX_GRADE)
		throw (Form::GradeTooHighException());
	if (gradeToSign > MIN_GRADE || gradeToExec > MIN_GRADE)
		throw (Form::GradeTooLowException());
	std::cout << "atribute form constructor called " << std::endl;
}

Form::Form(const Form& org): name(org.name), gradeToSign(org.gradeToSign), gradeToExec(org.gradeToExec), isSigned(false)
{
	*this = org;
}

Form::~Form()
{
	std::cout << "Form destructor" << std::endl;
}

// operadores

Form& Form::operator=(const Form &org)
{
	if (this != &org)
	{
		const_cast<std::string&>(this->name) = org.getName();
		const_cast<int&>(this->gradeToSign) = org.getGradeToSign();
		const_cast<int&>(this->gradeToExec) = org.getGradeToExec();
		this->isSigned = org.getIsSigned();
	}
	std::cout << "Copy Assigment operator called" << std::endl;
	return (*this);
}

std::ostream& operator<<(std::ostream &os, Form const &toPrint)
{
	os << "Form " <<  toPrint.getName() << ", \n grade to sign: " << toPrint.getGradeToSign() << ", \n grade to exec: " << toPrint.getGradeToExec();
	return (os);
}

// métodos de clase

std::string Form::getName() const
{
	return (this->name);
}

int	Form::getGradeToSign() const
{
	return (this->gradeToSign);
}

int Form::getGradeToExec() const
{
	return (this->gradeToExec);
}

bool Form::getIsSigned() const
{
	return (this->isSigned);
}

void Form::beSigned(Bureaucrat b)
{
	if (this->gradeToSign < b.getGrade())
		throw (Form::GradeTooLowException());
	this->isSigned = true;
}

// EXCEPCIONES

const char *Form::GradeTooHighException::what() const throw()
{
	return ("⚠️FORM: GRADE TOO HIGH ⚠️");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("⚠️ FORM: GRADE TOO LOW ⚠️");
}
