#include "ScavTrap.hpp"

// CONSTRUCTORES

ScavTrap::ScavTrap() : ClapTrap()
{
	this->hp = 100;
	this->energy = 50;
	this->damage = 20;
	this->name = "standard scavtrap idk";
}

ScavTrap::ScavTrap(std::string name)
{
	this->name = name;
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