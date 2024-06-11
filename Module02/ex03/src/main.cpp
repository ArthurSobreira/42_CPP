#include "Defines.hpp"
#include "Point.hpp"
#include "Fixed.hpp"
#include <iostream>
#include <sstream>

namespace Tests {
	void	repeatChar( char c, int n, std::string color ) {
		for (int i = 0; i < n; i++) {
			std::cout << color << c;
		}
		std::cout << RESET << std::endl;
	}

	std::string  printCoordinates( Point const &point ) {
		std::stringstream string;
		string << "(" << point.getX() << ", " << point.getY() << ")";
		return string.str();
	}

	void	validate( Point const a, Point const b, Point const c, Point const point ) {
		std::cout << "a is " << printCoordinates(a) << std::endl;
		std::cout << "b is " << printCoordinates(b) << std::endl;
		std::cout << "c is " << printCoordinates(c) << std::endl;
		std::cout << "point is " << printCoordinates(point) << std::endl;
		std::cout << "Is point inside triangle? " << \
		(bsp(a, b, c, point) ? YES : NO) << std::endl;
	}

	void	testPointInsideTriangle( void ) {
		Point const a( 0, 0 );
		Point const b( 4, 0 );
		Point const c( 2, 4 );
		Point const point( 2, 2 );

		validate(a, b, c, point);
	}

	void	testPointOutsideTriangle( void ) {
		Point const a( 0, 0 );
		Point const b( 4, 0 );
		Point const c( 2, 4 );
		Point const point( 2, 5 );

		validate(a, b, c, point);
	}

	void	testPointOnLine( void ) {
		Point const a( -2, -2 );
		Point const b( 0, 3 );
		Point const c( 2, -2 );
		Point const point( 1, -2 );

		validate(a, b, c, point);
	}

	void testPointOnEdge( void ) {
		Point const a( -2, -2 );
		Point const b( 0, 3 );
		Point const c( 2, -2 );
		Point const point( 0, 3 );

		validate(a, b, c, point);
	}
}

int main( void ) {
	Tests::repeatChar('=', 36, YELLOW);
	std::cout << "     Test Point Inside Triangle" << std::endl;
	Tests::repeatChar('=', 36, YELLOW);
	Tests::testPointInsideTriangle();

	Tests::repeatChar('=', 37, YELLOW);
	std::cout << "     Test Point Outside Triangle" << std::endl;
	Tests::repeatChar('=', 37, YELLOW);
	Tests::testPointOutsideTriangle();

	Tests::repeatChar('=', 28, YELLOW);
	std::cout << "     Test Point On Line" << std::endl;
	Tests::repeatChar('=', 28, YELLOW);
	Tests::testPointOnLine();

	Tests::repeatChar('=', 28, YELLOW);
	std::cout << "     Test Point On Edge" << std::endl;
	Tests::repeatChar('=', 28, YELLOW);
	Tests::testPointOnEdge();
	return 0;
}
