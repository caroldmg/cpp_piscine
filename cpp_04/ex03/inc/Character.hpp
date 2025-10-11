#pragma once
#include "ICharacter.hpp"

class Character : public  ICharacter
{
	private:
		std::string name;
		AMateria *mat[4];
		AMateria* floor[100];
	public:
		Character();
		Character(const Character& org);
		Character(std::string name);
		~Character();

		Character& operator=(const Character& org);

		std::string const & getName() const;
        void equip(AMateria* m);
        void use( int idx, ICharacter& target );
        void unequip( int idx );
		void cleanFloor();
};