#include "Defines.hpp"
#include "FragTrap.hpp"

namespace Tests {
	void	repeatChar( char c, int n, std::string color ) {
		for (int i = 0; i < n; i++) {
			std::cout << color << c;
		}
		std::cout << RESET << std::endl;
	}

	void	testDefaultConstructor( void ) {
		FragTrap frag1;
		
		frag1.attack("Target1");
		frag1.takeDamage(5);
		frag1.beRepaired(3);
		frag1.highFivesGuys();
	}

	void	testNameConstructor( void ) {
		FragTrap frag2("Fraggy");
		
		frag2.attack("Target2");
		frag2.takeDamage(8);
		frag2.setEnergyPoints(0);
		frag2.beRepaired(4);
		frag2.highFivesGuys();
	}

	void	testCopyConstructor( void ) {
		FragTrap frag3("Fraggy");
		FragTrap frag4(frag3);
		
		frag4.attack("Target3");
		frag4.takeDamage(100);
		frag4.beRepaired(5);
		frag4.highFivesGuys();
	}

	void	testCopyAssignmentOperator( void ) {
		FragTrap frag5("Fraggy");
		FragTrap frag6("Fragtrap");
		
		frag6 = frag5;
		frag6.attack("Target4");
		frag6.takeDamage(150);
		frag6.beRepaired(6);
		frag6.highFivesGuys();
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
