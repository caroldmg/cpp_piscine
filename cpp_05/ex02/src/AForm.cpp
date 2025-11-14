#include "AForm.hpp"

// constructores y destructores
AForm::AForm(): name("default"), gradeToSign(MIN_GRADE), gradeToExec(MIN_GRADE), isSigned(false)
{
	std::cout << "default AForm constructor" << std::endl;
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExec): name(name), gradeToSign(gradeToSign), gradeToExec(gradeToExec), isSigned(false)
{
	if (gradeToSign < MAX_GRADE || gradeToExec < MAX_GRADE)
		throw (AForm::GradeTooHighException());
	if (gradeToSign > MIN_GRADE || gradeToExec > MIN_GRADE)
		throw (AForm::GradeTooLowException());
	std::cout << "atribute AForm constructor called " << std::endl;
}

AForm::AForm(const AForm& org): name(org.name), gradeToSign(org.gradeToSign), gradeToExec(org.gradeToExec), isSigned(false)
{
	*this = org;
}

AForm::~AForm()
{
	std::cout << "AForm destructor" << std::endl;
}

// operadores

AForm& AForm::operator=(const AForm &org)
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

std::ostream& operator<<(std::ostream &os, AForm const &toPrint)
{
	os << "AForm " <<  toPrint.getName() << ", \n grade to sign: " << toPrint.getGradeToSign() << ", \n grade to exec: " << toPrint.getGradeToExec();
	return (os);
}

// métodos de clase

std::string AForm::getName() const
{
	return (this->name);
}

int	AForm::getGradeToSign() const
{
	return (this->gradeToSign);
}

int AForm::getGradeToExec() const
{
	return (this->gradeToExec);
}

bool AForm::getIsSigned() const
{
	return (this->isSigned);
}

void AForm::beSigned(Bureaucrat b)
{
	if (this->gradeToSign < b.getGrade())
		throw (AForm::GradeTooLowException());
	this->isSigned = true;
}

// EXCEPCIONES

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("⚠️FORM: GRADE TOO HIGH ⚠️");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("⚠️ FORM: GRADE TOO LOW ⚠️");
}
