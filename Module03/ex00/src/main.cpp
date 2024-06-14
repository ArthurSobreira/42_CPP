#include "Defines.hpp"
#include "ClapTrap.hpp"

namespace Tests {
	void	repeatChar( char c, int n, std::string color ) {
		for (int i = 0; i < n; i++) {
			std::cout << color << c;
		}
		std::cout << RESET << std::endl;
	}

	void	testDefaultConstructor( void ) {
		ClapTrap clap1;
		
		clap1.attack("Target1");
		clap1.takeDamage(5);
		clap1.beRepaired(3);
	}

	void	testNameConstructor( void ) {
		ClapTrap clap2("Clappy");
		
		clap2.attack("Target2");
		clap2.takeDamage(8);
		clap2.setEnergyPoints(0);
		clap2.beRepaired(4);
	}

	void	testCopyConstructor( void ) {
		ClapTrap clap3("Clappy");
		ClapTrap clap4(clap3);
		
		clap4.attack("Target3");
		clap4.takeDamage(10);
		clap4.beRepaired(5);
	}

	void	testCopyAssignmentOperator( void ) {
		ClapTrap clap5("Clappy");
		ClapTrap clap6("Claptrap");
		
		clap6 = clap5;
		clap6.attack("Target4");
		clap6.takeDamage(15);
		clap6.beRepaired(6);
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
