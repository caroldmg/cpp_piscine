#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	this->hp = 100;
	this->energy = 100;
	this->damage = 30;
	this->name = "something cool";
}

FragTrap::FragTrap(std::string name)
{
	this->name = name;
	std::cout << "FragTrap Constructor with name " << name << " called!" << std::endl;
}

FragTrap::FragTrap(const FragTrap& org)
{
	*this = org;
	std::cout << " FragTrap Copy constructor called!" << std::endl;
}

// DESTRUCTORES

FragTrap::~FragTrap()
{
	std::cout << " FragTrap Destructor called!" << std::endl;
}

// OPERADOR

FragTrap& FragTrap::operator=(const FragTrap& org)
{
	std::cout << "operator '=' overload here" << std::endl;
	this->setName(org.getName());
	this->setHp(org.getHp());
	this->setEnergy(org.getEnergy());
	this->setDamage(org.getDamage());
	return (*this);
}

void	FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << this->name <<  "raises their hand at you asking for you to clap it ✋" << std::endl;
}
