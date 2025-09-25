#include "ScavTrap.hpp"

void	announce(ClapTrap c)
{
	std::cout << "Hello! I am a ClapTrap and my name is " << c.getName() << std::endl;
}

int main()
{
	ScavTrap scav1;
	ScavTrap scav2("Supercolegui");
	ScavTrap scav3("Antonio");
	ScavTrap scav4(scav1);

	announce(scav1);
	announce(scav2);
	announce(scav3);
	announce(scav4);

	scav2.attack("someone");
	scav2.takeDamage(7);
	scav2.beRepaired(3);
	scav2.takeDamage(2);
	while (scav2.getEnergy() > 0)
		scav2.attack("everybody");
	scav2.beRepaired(3);
	while(scav2.getHp() > 0)
		scav2.takeDamage(1);
	scav3.guardGate();
}