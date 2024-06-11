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
		Fixed &operator=( const Fixed &other );

		/* Destructor Method */
		~Fixed( void );

		/* Public Methods */
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;

		/* Comparison Operators */
		bool	operator>( Fixed const &other ) const;
		bool	operator<( Fixed const &other ) const;
		bool	operator>=( Fixed const &other ) const;
		bool	operator<=( Fixed const &other ) const;
		bool	operator==( Fixed const &other ) const;
		bool	operator!=( Fixed const &other ) const;

		/* Arithmetic Operators */
		Fixed	operator+( Fixed const &other ) const;
		Fixed	operator-( Fixed const &other ) const;
		Fixed	operator*( Fixed const &other ) const;
		Fixed	operator/( Fixed const &other ) const;

		/* Increment and Decrement Operators */
		Fixed	&operator++( void );
		Fixed	operator++( int );
		Fixed	&operator--( void );
		Fixed	operator--( int );

		/* Min and Max */
		static Fixed	&min( Fixed &a, Fixed &b );
		static Fixed	&max( Fixed &a, Fixed &b );
		static Fixed const	&min( Fixed const &a, Fixed const &b );
		static Fixed const	&max( Fixed const &a, Fixed const &b );
};

std::ostream &operator<<( std::ostream &out, Fixed const &value );

#endif