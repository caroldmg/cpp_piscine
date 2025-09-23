#include "ClapTrap.hpp"

void	announce(ClapTrap c)
{
	std::cout << "Hello! I am a ClapTrap and my name is " << c.getName() << std::endl;
}

int main()
{
	ClapTrap clap1;
	ClapTrap clap2("Supercolegui");
	ClapTrap clap3("Antonio");
	ClapTrap clap4(clap3);

	announce(clap1);
	announce(clap2);
	announce(clap3);
	announce(clap4);

	clap2.attack("someone");
	clap2.takeDamage(7);
	clap2.beRepaired(3);
	clap2.takeDamage(2);
	while (clap2.getEnergy() > 0)
		clap2.attack("everybody");
	clap2.beRepaired(3);
	while(clap2.getHp() > 0)
		clap2.takeDamage(1);
	
	
}