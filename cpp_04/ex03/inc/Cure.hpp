#pragma once
#include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure();
		Cure(const Cure& org);
		~Cure();

		Cure& operator=(const Cure &org);

		AMateria*	clone() const;
		void		use(ICharacter& target);
};