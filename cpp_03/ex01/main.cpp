#include "ScavTrap.hpp"

void	announce(ClapTrap c)
{
	std::cout << "Hello! I am a ScavTrap and my name is " << c.getName() << std::endl;
}

void seeStats(ClapTrap &c, std::string color)
{
	std::cout << color << std::endl;
	std::cout << "------- " << c.getName() << " -------" << std::endl;
	std::cout << "Hit Points:  " << c.getHp() << std::endl;
	std::cout << "Energy Points:  " << c.getEnergy() << std::endl;
	std::cout << "Attack Damage:  " << c.getDamage() << std::endl;
	std::cout << "Ready to attack!" << std::endl;
	std::cout << "____________________" << std::endl;
	std::cout << RESET << std::endl;
}

int main()
{
	ScavTrap scav1;
	ScavTrap scav2("Supercolegui");
	ScavTrap scav3("Antonio");
	ScavTrap scav4(scav1);

	seeStats(scav1, GREEN);
	seeStats(scav2, RED);
	seeStats(scav3, YELLOW);
	seeStats(scav4, MAGENTA);

	std::cout << " \n \n START SIMULATION \n \t--------" << std::endl;

	scav2.attack("someone");
	scav2.takeDamage(7);
	scav2.beRepaired(3);
	scav2.takeDamage(2);
	scav2.setEnergy(1);
	scav2.attack("anyone");
	scav2.beRepaired(3);
	scav2.setHp(1);
	scav2.takeDamage(1);
	scav3.guardGate();
	scav2.guardGate();
	seeStats(scav1, GREEN);
	seeStats(scav2, RED);
	seeStats(scav3, YELLOW);
	seeStats(scav4, MAGENTA);

	std::cout << "\n ---- LET'S DESTROY EVERYTHING ---- \n" << std::endl;
}