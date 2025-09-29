#include "DiamondTrap.hpp"

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

// int main()
// {
// 	ClapTrap clap("Robotito");
// 	ScavTrap scav("Megarobotoneitor");
// 	FragTrap frag("Amiguito");
// 	DiamondTrap diamond("Pedazo de diamantote");


// 	seeStats(clap, RED);
// 	seeStats(scav, CYAN);
// 	seeStats(frag, MAGENTA);
// 	seeStats(diamond, YELLOW);
// 	/* 
// 		clap.stats(RED);
// 	scav.stats(CYAN);
// 	frag.stats(MAGENTA);
// 	diamond.stats(YELLOW); */

// 	std::cout << "\n ------ \t PELEEN 🤺⚔️🗡️ ------ \n" << std::endl;
// 	clap.attack(scav.getName());
// 	scav.takeDamage(clap.getDamage());
// 	scav.attack(frag.getName());
// 	frag.takeDamage(scav.getDamage());
// 	frag.attack(diamond.getName());
// 	diamond.takeDamage(frag.getDamage());
// 	diamond.attack(clap.getName());

// 	seeStats(clap, RED);
// 	seeStats(scav, CYAN);
// 	seeStats(frag, MAGENTA);
// 	seeStats(diamond, YELLOW);

// 	std::cout << "\n ---- \t AL TALLER!! ⚙️👷🏻👨‍🔧🛠️🔧 ---- \n" << std::endl;

// 	clap.beRepaired(10);
// 	scav.beRepaired(10);
// 	frag.beRepaired(10);
// 	diamond.beRepaired(10);

// 	seeStats(clap, RED);
// 	seeStats(scav, CYAN);
// 	seeStats(frag, MAGENTA);
// 	seeStats(diamond, YELLOW);

// 	std::cout << "\n --- GUARD GATE ---\n" << std::endl;
// 	scav.guardGate();
// 	diamond.guardGate();
// 	std::cout << " \t now we set HP to 0 " << std::endl;
// 	scav.setHp(0);
// 	scav.guardGate();

// 	// parte de high fives
// 	std::cout << "\n--- GOOD JOB! ---\n" << std::endl;
// 	frag.highFivesGuys();
// 	diamond.highFivesGuys();
// 	std::cout << " \t now we set HP to 0 " << std::endl;
// 	frag.setHp(0);
// 	frag.highFivesGuys();

// 	// who am i
// 	std::cout << " \n  --- Let's ask names ---\n " << std::endl;
// 	diamond.whoAmI();
// 	std::cout << " \t now we set HP to 0 " << std::endl;
// 	diamond.setHp(0);
// 	diamond.whoAmI();

// }

int main()
{
	DiamondTrap diamante1;
	seeStats(diamante1, GREEN);
	DiamondTrap diamante2("eo");
	seeStats(diamante2, MAGENTA);

}