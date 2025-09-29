#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("something cool", 100, 100, 30)
{
	std::cout << "FragTrap Default Constructor called!" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 100, 30)
{
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
	if (this->getHp() <= 0)
		std::cout << "FragTrap " << this->name << " would really love to hgh five you, but it's already dead and you cannot high five the dead ones (it would be really weird) 🧟⊹˚." << std::endl;
	else
		std::cout << "FragTrap " << this->name <<  " raises their hand at you asking for you to clap it ✋" << std::endl;
}
