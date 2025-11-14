#pragma once
#include "AForm.hpp"

/* 
	PresidentialPardonForm: Required grades: sign 25, exec 5
	Informs that <target> has been pardoned by Zaphod Beeblebrox.
*/

class PresidentialPardonForm: public AForm
{
	private:
		std::string target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &org);
		~PresidentialPardonForm();

		PresidentialPardonForm& operator=(const PresidentialPardonForm& org);

		virtual void execute(Bureaucrat const & executor) const;
		std::string getTarget() const;
};
