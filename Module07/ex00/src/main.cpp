#include "Defines.hpp"
#include "whatever.hpp"
#include <iostream>

int	main( void ) {
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

	return (0);
}
