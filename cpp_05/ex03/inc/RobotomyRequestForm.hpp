#pragma once
#include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm: public AForm
{
	private:
		std::string target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &org);
		~RobotomyRequestForm();

		RobotomyRequestForm& operator=(const RobotomyRequestForm& org);

		virtual void execute(Bureaucrat const & executor) const;
		std::string getTarget() const;
};
