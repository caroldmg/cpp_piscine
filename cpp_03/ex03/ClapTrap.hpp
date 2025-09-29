#pragma once
#include <iostream>

#define BLACK   "\033[1m\033[30m"
#define RED     "\033[1m\033[31m"
#define GREEN   "\033[1m\033[32m"
#define YELLOW  "\033[1m\033[33m"
#define BLUE    "\033[1m\033[34m"
#define MAGENTA "\033[1m\033[35m"
#define CYAN    "\033[1m\033[36m"
#define RESET   "\033[0m"

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
		ClapTrap(std::string name, int hp, int energy, int damage);
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
