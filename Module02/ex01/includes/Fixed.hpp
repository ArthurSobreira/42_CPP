#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
	private:
		int	_fixedPointValue;
		static const int _fractionalBits = 8;

	public:
		/* Constructor Methods */
		Fixed( void );
		Fixed( int const value );
		Fixed( float const value );

		/* Copy Constructor Method */
		Fixed( const Fixed &other );

		/* Copy Assignment Operator Overload */
		Fixed &operator=(const Fixed &other);

		/* Destructor Method */
		~Fixed();

		/* Public Methods */
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;
};

std::ostream &operator<<(std::ostream &out, Fixed const &value);

#endif