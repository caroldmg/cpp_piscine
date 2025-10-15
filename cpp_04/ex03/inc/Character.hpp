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

		virtual std::string const & getName() const;
        virtual void equip(AMateria* m);
        virtual void use( int idx, ICharacter& target );
        virtual void unequip( int idx );
		void cleanFloor();
};