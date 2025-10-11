#include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice();
		Ice(const Ice& org);
		~Ice();

		Ice& operator=(const Ice &org);

		AMateria* clone() const;
		void use(ICharacter& target);
};