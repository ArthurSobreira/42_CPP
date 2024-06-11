#include "Point.hpp"

/* Constructor Methods */
Point::Point( void ) : _x(0), _y(0) {};

Point::Point( const float x, const float y ) : _x(x), _y(y) {};

/* Copy Constructor Method */
Point::Point( const Point &other ) {
	*this = other;
}

/* Copy Assignment Operator Overload */
Point &Point::operator=( const Point &other ) {
	if (this != &other) {
		const_cast<Fixed&>(_x) = other.getX();
		const_cast<Fixed&>(_y) = other.getY();
	}
	return (*this);
}

/* Destructor Method */
Point::~Point() {};

/* Getter Methods */
Fixed const	Point::getX( void ) const {
	return (this->_x);
}

Fixed const Point::getY( void ) const {
	return (this->_y);
}
