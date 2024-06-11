#include "Defines.hpp"
#include "Fixed.hpp"
#include <iostream>

namespace Tests {
	void	repeatChar( char c, int n, std::string color ) {
		for (int i = 0; i < n; i++) {
			std::cout << color << c;
		}
		std::cout << RESET << std::endl;
	}

	void	testComparisonOperators( void ) {
		Fixed const a( 10 );
		Fixed const b( 20 );

		std::cout << "a is " << a << std::endl;
		std::cout << "b is " << b << std::endl;
		std::cout << "a < b is " << (a < b) << std::endl;
		std::cout << "a > b is " << (a > b) << std::endl;
		std::cout << "a <= b is " << (a <= b) << std::endl;
		std::cout << "a >= b is " << (a >= b) << std::endl;
		std::cout << "a == b is " << (a == b) << std::endl;
		std::cout << "a != b is " << (a != b) << std::endl;
	}

	void	testArithmeticOperators ( void ) {
		Fixed const a( 5 );
		Fixed const b( 10 );

		std::cout << "a is " << a << std::endl;
		std::cout << "b is " << b << std::endl;
		std::cout << "a + b is " << (a + b) << std::endl;
		std::cout << "a - b is " << (a - b) << std::endl;
		std::cout << "a * b is " << (a * b) << std::endl;
		std::cout << "a / b is " << (a / b) << std::endl;
	}

	void	testIncrementDecrementOperators( void ) {
		Fixed a( 0 );
		Fixed b( 2 );

		std::cout << "a is "   << a << std::endl;
		std::cout << "b is "   << b << std::endl;
		std::cout << "a++ is " << a++ << std::endl;
		std::cout << "b++ is " << b++ << std::endl;
		std::cout << "a is "   << a << std::endl;
		std::cout << "b is "   << b << std::endl;
		std::cout << "++a is " << ++a << std::endl;
		std::cout << "++b is " << ++b << std::endl;
		std::cout << "a-- is " << a-- << std::endl;
		std::cout << "b-- is " << b-- << std::endl;
		std::cout << "--a is " << --a << std::endl;
		std::cout << "--b is " << --b << std::endl;
	}
}

int main( void ) {
	Tests::repeatChar('=', 38, WHITE);
	std::cout << "     Testing Comparison Operators" << std::endl;
	Tests::repeatChar('=', 38, WHITE);
	Tests::testComparisonOperators();

	Tests::repeatChar('=', 38, WHITE);
	std::cout << "     Testing Arithmetic Operators" << std::endl;
	Tests::repeatChar('=', 38, WHITE);
	Tests::testArithmeticOperators();

	Tests::repeatChar('=', 51, WHITE);
	std::cout << "     Testing Increment and Decrement Operators" << std::endl;
	Tests::repeatChar('=', 51, WHITE);
	Tests::testIncrementDecrementOperators();

	return (0);
}
