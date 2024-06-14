#include "Defines.hpp"
#include "DiamondTrap.hpp"

namespace Tests {
	void	repeatChar( char c, int n, std::string color ) {
		for (int i = 0; i < n; i++) {
			std::cout << color << c;
		}
		std::cout << RESET << std::endl;
	}

	void	testDefaultConstructor( void ) {
		DiamondTrap diam1;
		
		diam1.attack("Target1");
		diam1.takeDamage(5);
		diam1.beRepaired(3);
		diam1.guardGate();
		diam1.highFivesGuys();
		diam1.whoAmI();
	}

	void	testNameConstructor( void ) {
		DiamondTrap diam2("Diamondy");
		
		diam2.attack("Target2");
		diam2.takeDamage(8);
		diam2.setEnergyPoints(0);
		diam2.beRepaired(4);
		diam2.guardGate();
		diam2.highFivesGuys();
		diam2.whoAmI();
	}

	void	testCopyConstructor( void ) {
		DiamondTrap diam3("Diamondy");
		DiamondTrap diam4(diam3);
		
		diam4.attack("Target3");
		diam4.takeDamage(100);
		diam4.beRepaired(5);
		diam4.guardGate();
		diam4.highFivesGuys();
		diam4.whoAmI();
	}

	void	testCopyAssignmentOperator( void ) {
		DiamondTrap diam5("Diamondy");
		DiamondTrap diam6("Diamtrap");
		
		diam6 = diam5;
		diam6.attack("Target4");
		diam6.takeDamage(150);
		diam6.beRepaired(6);
		diam6.guardGate();
		diam6.highFivesGuys();
		diam6.whoAmI();
	}
}

int main( void ) {
	Tests::repeatChar('=', 37, CYAN);
	std::cout << "     Testing Default Constructor" << std::endl;
	Tests::repeatChar('=', 37, CYAN);
	Tests::testDefaultConstructor();

	Tests::repeatChar('=', 34, CYAN);
	std::cout << "     Testing Name Constructor" << std::endl;
	Tests::repeatChar('=', 34, CYAN);
	Tests::testNameConstructor();

	Tests::repeatChar('=', 34, CYAN);
	std::cout << "     Testing Copy Constructor" << std::endl;
	Tests::repeatChar('=', 34, CYAN);
	Tests::testCopyConstructor();

	Tests::repeatChar('=', 42, CYAN);
	std::cout << "     Testing Copy Assignment Operator" << std::endl;
	Tests::repeatChar('=', 42, CYAN);
	Tests::testCopyAssignmentOperator();

	return (0);
}
