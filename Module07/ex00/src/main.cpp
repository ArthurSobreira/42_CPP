#include "Defines.hpp"
#include "whatever.hpp"
#include <iostream>

namespace Tests {
	void	repeatChar( char c, int n, std::string color ) {
		for (int i = 0; i < n; i++) {
			std::cout << color << c;
		}
		std::cout << RESET << std::endl;
	}

	void	subjectTests( void ) {
		int a = 2;
		int b = 3;

		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << COLORIZE(BLUE, "min( a, b )") << " = " << 
		::min( a, b ) << std::endl;
		std::cout << COLORIZE(MAGENTA, "max( c, d )") << " = " << 
		::max( a, b ) << std::endl;

		std::string c = "chaine1";
		std::string d = "chaine2";

		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << COLORIZE(BLUE, "min( a, b )") << " = " << 
		::min( c, d ) << std::endl;
		std::cout << COLORIZE(MAGENTA, "max( c, d )") << " = " << 
		::max( c, d ) << std::endl;
	}

	void	stringTests( void ) {
		std::string str1 = "Cool String2";
		std::string str2 = "Cool String1";

		::swap( str1, str2 );
		std::cout << "str1 = " << str1 << std::endl;
		std::cout << "str2 = " << str2 << std::endl;
		std::cout << COLORIZE(BLUE, "min( str1, str2 )") << " = " <<
		::min( str1, str2 ) << std::endl;
		std::cout << COLORIZE(MAGENTA, "max( str1, str2 )") << " = " <<
		::max( str1, str2 ) << std::endl;
	}

	void	floatTests( void ) {
		float a = 2.3f;
		float b = 5.7f;

		::swap( a, b );
		std::cout << "number a = " << a << std::endl;
		std::cout << "number b = " << b << std::endl;
		std::cout << COLORIZE(BLUE, "min( a, b )") << " = " << 
		::min( a, b ) << std::endl;
		std::cout << COLORIZE(MAGENTA, "max( c, d )") << " = " << 
		::max( a, b ) << std::endl;
	}

	void	InvalidTests( void ) {
		std::string str = "Bad String";
		int	number = 4242;

		std::cout << "str = " << str << std::endl;
		std::cout << "number = " << number << std::endl;
		/* 
		::swap( str, number );  // Invalid arguments type
		 */
	}
}

int	main( void ) {
	Tests::repeatChar('=', 33, BOLD_CYAN);
	std::cout << "          Subject Tests " << std::endl;
	Tests::repeatChar('=', 33, BOLD_CYAN);
	Tests::subjectTests();

	Tests::repeatChar('=', 33, BOLD_CYAN);
	std::cout << "      Template String Tests " << std::endl;
	Tests::repeatChar('=', 33, BOLD_CYAN);
	Tests::stringTests();

	Tests::repeatChar('=', 33, BOLD_CYAN);
	std::cout << "      Template Float Tests " << std::endl;
	Tests::repeatChar('=', 33, BOLD_CYAN);
	Tests::floatTests();

	Tests::repeatChar('=', 33, BOLD_CYAN);
	std::cout << "          Invalid Tests " << std::endl;
	Tests::repeatChar('=', 33, BOLD_CYAN);
	Tests::InvalidTests();

	return (0);
}
