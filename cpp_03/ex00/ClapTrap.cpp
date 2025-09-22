#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): hp(10), energy(10), damage(0)
{
	this->name = "non";
	std::cout << "Empty constructor called!" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : hp(10), energy(10), damage(0)
{
	this->name = name;
	std::cout << "Constructor with name " << name << " called!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& org)
{
	*this = org;
	std::cout << "Copy constructor called!" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called!" << std::endl;
}

// operator

ClapTrap& ClapTrap::operator=(const ClapTrap &org)
{
	std::cout << "operator '=' overload here" << std::endl;
	this->setName(org.getName());
	this->setHp(org.getHp());
	this->setEnergy(org.getEnergy());
	this->setDamage(org.getDamage());
}

// getters

std::string ClapTrap::getName() const
{
	return (this->name);
}

unsigned int ClapTrap::getHp() const
{
	return (this->hp);
}
unsigned int ClapTrap::getDamage() const
{
	return (this->damage);
}

unsigned int ClapTrap::getEnergy() const
{
	return (this->energy);
}

// setters

void ClapTrap::setName(std::string name)
{
	this->name = name;
}

void ClapTrap::setHp(unsigned int hp)
{
	this->hp = hp;
}

void ClapTrap::setEnergy(unsigned int energy)
{
	this->energy = energy;
}

void ClapTrap::setDamage(unsigned int damage)
{
	this->damage = damage;
}

// member functions

void ClapTrap::attack(const std::string &target)
{
	// si no tiene energia nanai
	if (this->energy == 0)
	{
		std::cout << " -- 🔋TOO TIRED!!🔋 -- clapTrap" << this->getName() << "cannot attack because it has no energy left :(" << std::endl;
		return ;
	}
	std::cout << " ClapTrap " << this->name << " attacks " << target << ", causing" << this->damage << " points of damage! 💥" << std::endl;
	setEnergy(this->getEnergy() - 1);
	// this->energy--;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->getEnergy() == 0)
	{
		std::cout << " -- 🔋 TOO TIRED!! 🔋 -- clapTrap" << this->getName() << " cannot repair itself because it has no energy left :(" << std::endl;
		return ;
	}
	if (this->getHp() == 0)
	{
		std::cout << " ClapTrap " << this->getName() << " cannot reapir itself because it's already dead 🪦🌹" << std::endl;
		return ;
	}
	std::cout << " ClapTrap " << this->getName() << " repairs itself! it now has " << this->getHp() << " HP!" << std::endl;
	setHp(this->getHp() + amount);
	setEnergy(this->getEnergy() - 1);
	// this->hp+= amount;
	// this->energy--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->getHp() == 0)
	{
		std::cout << "ClapTrap" << this->getName() << " cannot take anymore damage " << std::endl;
		return ;
	}
	this->setHp(getHp() - amount);
	std::cout << "💥 ClapTrap " << this->getName() << "has been attacked!!💥 ClapTrap looses " << amount << "HP!!" << std::endl;
	if (this->getHp() == 0)
	{
		std::cout << "Claptrap " << this->getName() << "has now died. 🪦🌹"
	}
}