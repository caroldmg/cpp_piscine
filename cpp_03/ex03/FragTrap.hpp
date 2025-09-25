#pragma once
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	private:

	public:
		FragTrap();
		FragTrap(const FragTrap& org);
		FragTrap(std::string name);
		~FragTrap();

		FragTrap& operator=(const FragTrap& org);

		void	highFivesGuys();
};