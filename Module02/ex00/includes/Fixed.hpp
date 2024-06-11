#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
	private:
		int	_fixedPointValue;
		static const int _fractionalBits = 8;

	public:
		/* Constructor Method */
		Fixed( void );

		/* Copy Constructor Method */
		Fixed( const Fixed &other );

		/* Copy Assignment Operator Overload */
		Fixed &operator=(const Fixed &rhs);

		/* Destructor Method */
		~Fixed();

		/* Public Methods */
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
};

#endif