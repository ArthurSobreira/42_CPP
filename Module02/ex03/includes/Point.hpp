#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point {
	private:
		Fixed const	_x;
		Fixed const	_y;

	public:
		/* Constructor Methods */
		Point( void );
		Point( const float x, const float y );

		/* Copy Constructor Method */
		Point( const Point &other );

		/* Copy Assignment Operator Overload */
		Point &operator=( const Point &other );

		/* Destructor Method */
		~Point( void );

		/* Getter Methods */
		Fixed const	getX( void ) const;
		Fixed const	getY( void ) const;
};

#endif
