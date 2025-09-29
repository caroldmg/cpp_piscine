#include "ScavTrap.hpp"

// CONSTRUCTORES

ScavTrap::ScavTrap() : ClapTrap("standard scavtrap idk", 100, 50, 20)
{
	std::cout << " ScavTrap Constructor called!" << std::endl;
	
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 20)
{
	std::cout << " ScavTrap Constructor with name " << name << " called!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& org)
{
	*this = org;
	std::cout << " ScavTrap Copy constructor called!" << std::endl;
}

// DESTRUCTORES

ScavTrap::~ScavTrap()
{
	std::cout << " ScavTrap Destructor called!" << std::endl;
}

// OPERADOR

ScavTrap& ScavTrap::operator=(const ScavTrap& org)
{
	std::cout << "operator '=' overload here" << std::endl;
	this->setName(org.getName());
	this->setHp(org.getHp());
	this->setEnergy(org.getEnergy());
	this->setDamage(org.getDamage());
	return (*this);
}

// MEMBER FUNCTIONS

void ScavTrap::attack(const std::string &target)
{
	if (this->getEnergy() == 0)
	{
		std::cout << " -- 🔋TOO TIRED!!🔋 -- ScavTrap -" << this->getName() << "- cannot attack because it has no energy left :(" << std::endl;
		return ;
	}
	this->setEnergy(this->getEnergy() - 1);
	std::cout << " ScavTrap " << this->getName() << " attacks " << target << ", causing " << this->getDamage() << " points of damage! 💥" << " --- it now has "<< this->getEnergy() << " energy points🔋 --- " << std::endl;
}

void	ScavTrap::guardGate()
{
	if (this->getHp() <= 0)
		std::cout << "ScavTrap " << this->getName() << " is dead and cannot guard the gate ☠️ " << std::endl;
	else
		std::cout << "ScavTrap " << this->getName() << " is now in Gate Keeper mode ⚔️ " << std::endl;
}