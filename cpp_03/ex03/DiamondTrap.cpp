#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap()
{
	std::cout << "DiamondTrap constructor called " << std::endl;
	this->hp = 100;
	this->energy = 50;
	this->damage = 30;
	this->name = "DiamondTrap default";
	ClapTrap::name == name + "_clap_name";
}

DiamondTrap::DiamondTrap(std::string name)
{
	this->name = name;
	std::cout << " DiamondTrap Constructor with name " << name << " called!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& org)
{
	*this = org;
	std::cout << " DiamondTrap Copy constructor called!" << std::endl;
}

// DESTRUCTOR

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called here " << std::endl;
}


DiamondTrap& DiamondTrap::operator=(const DiamondTrap& org)
{
	std::cout << "operator '=' overload here" << std::endl;
	this->setName(org.getName());
	this->setHp(org.getHp());
	this->setEnergy(org.getEnergy());
	this->setDamage(org.getDamage());
	return (*this);
}

void	DiamondTrap::whoAmI()
{
	std::cout << "This DiamondTrap's name is " << this->getName() << "but my real name is " << ClapTrap::getName() << std::endl;
}