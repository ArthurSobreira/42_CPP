#include "Fixed.hpp"
#include <cmath>

/* Constructor Methods */
Fixed::Fixed( void ) : _fixedPointValue(0) {};

Fixed::Fixed( int const value ) {
	_fixedPointValue = value << _fractionalBits;
}

Fixed::Fixed( float const value ) {
	_fixedPointValue = static_cast<int>(roundf(value * (1 << _fractionalBits)));
}

/* Copy Constructor Method */
Fixed::Fixed( const Fixed &other ) {
	*this = other;
}

/* Copy Assignment Operator Overload */
Fixed &Fixed::operator=( const Fixed &other ) {
	if (this != &other)
		this->_fixedPointValue = other.getRawBits();
	return (*this);
}

/* Destructor Method */
Fixed::~Fixed( void ) {};

/* Getter and Setter RawBits */
int	Fixed::getRawBits( void ) const {
	return (this->_fixedPointValue);
}

void	Fixed::setRawBits( int const raw ) {
	this->_fixedPointValue = raw;
}

/* Conversion Methods */
float	Fixed::toFloat( void ) const {
	return ((float)(this->_fixedPointValue) / (1 << _fractionalBits));
}

int Fixed::toInt( void ) const {
	return (this->_fixedPointValue >> _fractionalBits);
}

/* Output Operator Overload */
std::ostream &operator<<( std::ostream &out, Fixed const &value ) {
	out << value.toFloat();
	return (out);
}
