#include "ClapTrap.hpp"

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
	ClapTrap clap1;
	ClapTrap clap2("Supercolegui");
	ClapTrap clap3("Antonio");
	ClapTrap clap4(clap3);

	seeStats(clap1, GREEN);
	seeStats(clap2, CYAN);
	seeStats(clap3, MAGENTA);
	seeStats(clap4, RED);

	clap2.attack("someone");
	clap2.takeDamage(7);
	clap2.beRepaired(3);
	clap2.takeDamage(2);
	while (clap2.getEnergy() > 0)
		clap2.attack("everybody");
	clap2.beRepaired(3);
	while(clap2.getHp() > 0)
		clap2.takeDamage(1);
	
	seeStats(clap1, GREEN);
	seeStats(clap2, CYAN);
	seeStats(clap3, MAGENTA);
	seeStats(clap4, RED);
}