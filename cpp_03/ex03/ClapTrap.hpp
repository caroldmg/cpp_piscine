#pragma once
#include <iostream>

class ClapTrap
{
	protected:
		std::string		name;
		unsigned int	hp;
		unsigned int	energy;
		unsigned int	damage;
	public:
		ClapTrap();
		ClapTrap(const ClapTrap& org);
		ClapTrap(std::string name);
		~ClapTrap();

		ClapTrap&	operator=(const ClapTrap &org);

		virtual void	attack(const std::string &target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);

		// get & set
		std::string		getName() const;
		unsigned int	getHp() const;
		unsigned int	getEnergy() const;
		unsigned int	getDamage() const;
		void			setName(std::string name);
		void			setHp(unsigned int hp);
		void			setEnergy(unsigned int energy);
		void			setDamage(unsigned int damage);

};
