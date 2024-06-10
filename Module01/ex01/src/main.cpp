#include "Defines.hpp"
#include "Zombie.hpp"

namespace Tests {
	void	repeatChar( char c, int n, std::string color ) {
		for (int i = 0; i < n; i++) {
			std::cout << color << c;
		}
		std::cout << RESET << std::endl;
	}

	void	testZombieHorde( void ) {
		Zombie	*zHorde = zombieHorde(5, "NecroKnight");

		for (int i = 0; i < 5; i++) {
			zHorde[i].announce();
		}
		delete [] zHorde;
	}

	void	testZombieHordeLeak( void ) {
		Zombie	*zHorde = zombieHorde(5, "NecroNinja");

		for (int i = 0; i < 5; i++) {
			zHorde[i].announce();
		}
		delete [] zHorde;  // Comment this line to leak memory
	}
}

int	main( void ) {
	Tests::repeatChar('=', 30, WHITE);
	std::cout << "     Testing Zombie Horde" << std::endl;
	Tests::repeatChar('=', 30, WHITE);
	Tests::testZombieHorde();

	Tests::repeatChar('=', 33, WHITE);
	std::cout << "     Testing Zombie Horde Leak" << std::endl;
	Tests::repeatChar('=', 33, WHITE);
	Tests::testZombieHordeLeak();

	return (0);
}
