#include "Fixed.hpp"
#include <cmath>

/* Constructor Methods */
Fixed::Fixed( void ) : _fixedPointValue(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( int const value ) {
	std::cout << "Int constructor called" << std::endl;
	_fixedPointValue = value << _fractionalBits;
}

Fixed::Fixed( float const value ) {
	std::cout << "Float constructor called" << std::endl;
	_fixedPointValue = static_cast<int>(roundf(value * (1 << _fractionalBits)));
}

/* Copy Constructor Method */
Fixed::Fixed( const Fixed &other ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

/* Copy Assignment Operator Overload */
Fixed &Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_fixedPointValue = other.getRawBits();
	return (*this);
}

/* Destructor Method */
Fixed::~Fixed( void ) {
	std::cout << "Destructor called" << std::endl;
}

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
std::ostream &operator<<(std::ostream &out, Fixed const &value) {
	out << value.toFloat();
	return (out);
}
