#pragma once
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	private:

	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap& org);
		~FragTrap();

		FragTrap& operator=(const FragTrap& org);

		void	highFivesGuys();
};