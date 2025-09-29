#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("")
{
	std::cout << "DiamondTrap constructor called " << std::endl;
	this->hp = 100;
	this->energy = 50;
	this->damage = 30;
	this->name = "DiamondTrap default";
	ClapTrap::name = name + "_clap_name";
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name)
{
	ClapTrap::name = name + "_clap_name";
	this->name = name;
	this->hp = 100;
	this->energy = 50;
	this->damage = 30;

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

std::string DiamondTrap::getDiamondName()
{
	return (this->name);
}


DiamondTrap& DiamondTrap::operator=(const DiamondTrap& org)
{
	std::cout << "operator '=' overload here" << std::endl;
	this->setName(org.name);
	this->setHp(org.getHp());
	this->setEnergy(org.getEnergy());
	this->setDamage(org.getDamage());
	return (*this);
}

void	DiamondTrap::whoAmI()
{
	if (this->getHp() <= 0)
	{
		std::cout << "🪦 you reach a tomb. You walk towards it and read : ' Here lies " << this->getDiamondName() << " beloved DiamondTrap💎 and husband, born known as " << ClapTrap::getName() << " ' and we will always remember him. " << std::endl;
		std::cout << "You leave a flower as a tear runs down your face (*ᴗ͈ˬᴗ͈)ꕤ*.ﾟ" << std::endl;
	}
	else
	{
		std::cout << "You asked this DiamondTrap it's name, as if it would really reveals you who he truly is." << std::ends;
		std::cout << "This DiamondTrap answers: " << GREEN << "\n \t'An eternity would not be enough to tell you who I am, but others call me " << this->getDiamondName() << " and if you ask for my ancerstors' name, it is " << ClapTrap::getName() << " Hope this helps. '" << RESET << "\n What a kind being." << std::endl;
	}
}

void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}