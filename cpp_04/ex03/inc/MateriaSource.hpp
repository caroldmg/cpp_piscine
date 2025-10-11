#pragma once
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria *mats[4];

	public:
		MateriaSource();
		MateriaSource(const MateriaSource& org);
		~MateriaSource();

		MateriaSource& operator=(const MateriaSource& org);

		void learnMateria(AMateria* materia);
		AMateria* createMateria(std::string const & type);
};
