#include "ClapTrap.hpp"
#pragma once

class ScavTrap : virtual public ClapTrap
{
	private:
		// no a la privatización de atributos I guess??
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& org);
		~ScavTrap();

		ScavTrap& operator=(const ScavTrap& org);

		void	attack(const std::string& target) override;
		void	guardGate();
};

