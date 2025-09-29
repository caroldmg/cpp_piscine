#include "FragTrap.hpp"

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
	FragTrap frag1;
	FragTrap frag2("Supercolegui");
	FragTrap frag3("Antonio");
	FragTrap frag4(frag1);

	seeStats(frag1, GREEN);
	seeStats(frag2, RED);
	seeStats(frag3, YELLOW);
	seeStats(frag4, MAGENTA);

	std::cout << " \n \n START SIMULATION \n \t--------" << std::endl;
	frag2.attack("someone");
	frag2.takeDamage(7);
	frag2.beRepaired(3);
	frag2.takeDamage(2);
	frag2.attack("everybody");
	frag2.setEnergy(0);
	frag2.attack("someone");
	frag2.beRepaired(3);
	std::cout << "ahora a este le cambiamos los HP a 1 y le hacemos recibir daño ----"  << std::endl;
	frag3.setHp(1);
	frag3.takeDamage(1);
	frag3.takeDamage(1);

	seeStats(frag1, GREEN);
	seeStats(frag2, RED);
	seeStats(frag3, YELLOW);
	seeStats(frag4, MAGENTA);
	
	std::cout << "--- high five!!! \n " << std::endl;
	frag3.highFivesGuys();
	frag2.highFivesGuys();
	
	std::cout << "\n ---- LET'S DESTROY EVERYTHING ---- \n" << std::endl;

}