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

	void	testSubject( void ) {
		Fixed 		a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;

		std::cout << b << std::endl;

		std::cout << Fixed::max( a, b ) << std::endl;
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

	void	testMinMaxOperators( void ) {
		Fixed a( 0 );
		Fixed b( 2 );
		Fixed const c( 5 );
		Fixed const d( 3 );

		std::cout << "a is " << a << std::endl;
		std::cout << "b is " << b << std::endl;
		std::cout << "min(a, b) is " << Fixed::min(a, b) << std::endl;
		std::cout << "max(a, b) is " << Fixed::max(a, b) << std::endl;
		std::cout << "c is " << c << std::endl;
		std::cout << "d is " << d << std::endl;
		std::cout << "min(c, d) is " << Fixed::min(c, d) << std::endl;
		std::cout << "max(c, d) is " << Fixed::max(c, d) << std::endl;
	}
}

int main( void ) {
	Tests::repeatChar('=', 25, WHITE);
	std::cout << "     Testing Subject" << std::endl;
	Tests::repeatChar('=', 25, WHITE);
	Tests::testSubject();

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

	Tests::repeatChar('=', 39, WHITE);
	std::cout << "     Testing Min and Max Operators" << std::endl;
	Tests::repeatChar('=', 39, WHITE);
	Tests::testMinMaxOperators();
	return (0);
}
