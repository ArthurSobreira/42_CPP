#include "Defines.hpp"
#include "Zombie.hpp"

namespace Tests {
	void	repeatChar( char c, int n, std::string color ) {
		for (int i = 0; i < n; i++) {
			std::cout << color << c;
		}
		std::cout << RESET << std::endl;
	}

	void	testLocalZombie( void ) {
		Zombie zombie;

		zombie.setName("Rotjaw the Haunter");
		zombie.announce();
	}

	void	testRandomChump( void ) {
		randomChump("Zedrick the Undying");
	}

	void	testNewZombie( void ) {
		Zombie* zombie = newZombie("Mortis Shadowsoul");

		zombie->announce();
		delete zombie;
	}

	void testNewZombieLeak( void ) {
		Zombie* zombie = newZombie("Grimfang the Restless");
		
		zombie->announce();
		delete zombie;  // Comment this line to leak memory
	}
}

int	main ( void ) {
	Tests::repeatChar('=', 24, WHITE);
	std::cout << "  Testing Local Zombie" << std::endl;
	Tests::repeatChar('=', 24, WHITE);
	Tests::testLocalZombie();

	Tests::repeatChar('=', 24, WHITE);
	std::cout << "  Testing Random Chump" << std::endl;
	Tests::repeatChar('=', 24, WHITE);
	Tests::testRandomChump();

	Tests::repeatChar('=', 22, WHITE);
	std::cout << "  Testing New Zombie" << std::endl;
	Tests::repeatChar('=', 22, WHITE);
	Tests::testNewZombie();

	Tests::repeatChar('=', 27, WHITE);
	std::cout << "  Testing New Zombie Leak" << std::endl;
	Tests::repeatChar('=', 27, WHITE);
	Tests::testNewZombieLeak();

	return (0);
}
