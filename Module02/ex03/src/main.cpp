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

	void	testPointInsideTriangle( void ) {
		Point const a( 0, 0 );
		Point const b( 4, 0 );
		Point const c( 2, 4 );
		Point const point( 2, 2 );

		std::cout << "a is " << printCoordinates(a) << std::endl;
		std::cout << "b is " << printCoordinates(b) << std::endl;
		std::cout << "c is " << printCoordinates(c) << std::endl;
		std::cout << "point is " << printCoordinates(point) << std::endl;
		std::cout << "Is point inside triangle? " << \
		(bsp(a, b, c, point) ? "Yes" : "No") << std::endl;
	}

	void	testPointOutsideTriangle( void ) {
		Point const a( 0, 0 );
		Point const b( 4, 0 );
		Point const c( 2, 4 );
		Point const point( 2, 5 );

		std::cout << "a is " << printCoordinates(a) << std::endl;
		std::cout << "b is " << printCoordinates(b) << std::endl;
		std::cout << "c is " << printCoordinates(c) << std::endl;
		std::cout << "point is " << printCoordinates(point) << std::endl;
		std::cout << "Is point inside triangle? " << \
		(bsp(a, b, c, point) ? "Yes" : "No") << std::endl;
	}

	void	testPointOnTriangle( void ) {
		Point const a( 0, 0 );
		Point const b( 4, 0 );
		Point const c( 2, 4 );
		Point const point( 2, 0 );

		std::cout << "a is " << printCoordinates(a) << std::endl;
		std::cout << "b is " << printCoordinates(b) << std::endl;
		std::cout << "c is " << printCoordinates(c) << std::endl;
		std::cout << "point is " << printCoordinates(point) << std::endl;
		std::cout << "Is point inside triangle? " << \
		(bsp(a, b, c, point) ? "Yes" : "No") << std::endl;
	}
}

int main( void ) {
	Tests::repeatChar('=', 40, YELLOW);
	std::cout << "     Test Point Inside Triangle" << std::endl;
	Tests::repeatChar('=', 40, YELLOW);
	Tests::testPointInsideTriangle();

	Tests::repeatChar('=', 40, YELLOW);
	std::cout << "     Test Point Outside Triangle" << std::endl;
	Tests::repeatChar('=', 40, YELLOW);
	Tests::testPointOutsideTriangle();

	Tests::repeatChar('=', 40, YELLOW);
	std::cout << "     Test Point On Triangle" << std::endl;
	Tests::repeatChar('=', 40, YELLOW);
	return 0;
}
