#pragma once
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap :  public ScavTrap, public ClapTrap
{
	private:
		std::string name;
	public:
		DiamondTrap();
		DiamondTrap();
		DiamondTrap(const DiamondTrap& org);
		~DiamondTrap();

		DiamondTrap&	operator=(const DiamondTrap &org);

};