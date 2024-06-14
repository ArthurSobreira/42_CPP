#include "Defines.hpp"
#include "ScavTrap.hpp"

namespace Tests {
	void	repeatChar( char c, int n, std::string color ) {
		for (int i = 0; i < n; i++) {
			std::cout << color << c;
		}
		std::cout << RESET << std::endl;
	}

	void	testDefaultConstructor( void ) {
		ScavTrap scav1;
		
		scav1.attack("Target1");
		scav1.takeDamage(5);
		scav1.beRepaired(3);
		scav1.guardGate();
	}

	void	testNameConstructor( void ) {
		ScavTrap scav2("Scavvy");
		
		scav2.attack("Target2");
		scav2.takeDamage(8);
		scav2.setEnergyPoints(0);
		scav2.beRepaired(4);
		scav2.guardGate();
	}

	void	testCopyConstructor( void ) {
		ScavTrap scav3("Scavvy");
		ScavTrap scav4(scav3);
		
		scav4.attack("Target3");
		scav4.takeDamage(100);
		scav4.beRepaired(5);
		scav4.guardGate();
	}

	void	testCopyAssignmentOperator( void ) {
		ScavTrap scav5("Scavvy");
		ScavTrap scav6("Scavtrap");
		
		scav6 = scav5;
		scav6.attack("Target4");
		scav6.takeDamage(150);
		scav6.beRepaired(6);
		scav6.guardGate();
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
