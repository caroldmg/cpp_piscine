#pragma once
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap :  public ScavTrap, public FragTrap
{
	private:
		std::string name;
	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap& org);
		~DiamondTrap();

		DiamondTrap&	operator=(const DiamondTrap &org);

		void			attack(const std::string &target);
		void			whoAmI();
		std::string		getDiamondName();
};