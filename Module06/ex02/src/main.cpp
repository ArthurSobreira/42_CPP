#include "Defines.hpp"
#include "Base.hpp"
#include <iostream>

namespace Tests {
	void	repeatChar( char c, int n, std::string color ) {
		for (int i = 0; i < n; i++) {
			std::cout << color << c;
		}
		std::cout << RESET << std::endl;
	}

	void	testIdentifyFromPointerAndReference( void ) {
		for (size_t i = 0; i < 3; i++)
		{
			Base	*base = generate();

			std::cout << COLORIZE(YELLOW, "Identify Base from Pointer:   ");
			identify(base);
			std::cout << COLORIZE(YELLOW, "Identify Base from Reference: ");
			identify(*base);
			std::cout << std::endl;

			delete base;
		}
		/* Test with NULL pointer */
		identify(NULL);
	}

}

int main( void ) {
	Tests::repeatChar('=', 55, CYAN);
	std::cout << "     Test Identify Base from Pointer and Reference " << std::endl;
	Tests::repeatChar('=', 55, CYAN);
	Tests::testIdentifyFromPointerAndReference();

	return (0);
}