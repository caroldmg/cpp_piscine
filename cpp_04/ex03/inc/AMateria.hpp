#pragma once
#include <iostream>
#include "ICharacter.hpp"

class ICharacter;
class AMateria
{
	protected:
		std::string type;
	public:
		AMateria();
		AMateria(const AMateria& org);
		AMateria (std::string const & type);
		virtual ~AMateria();

		AMateria& operator=(const AMateria &org);

		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};