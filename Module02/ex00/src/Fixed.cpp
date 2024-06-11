#include "Fixed.hpp"

/* Constructor Method */
Fixed::Fixed( void ) : _fixedPointValue(0) {
	std::cout << "Default constructor called" << std::endl;
}

/* Copy Constructor Method */
Fixed::Fixed( const Fixed &other ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

/* Copy Assignment Operator Overload */
Fixed &Fixed::operator=( const Fixed &other ) {
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
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedPointValue);
}

void	Fixed::setRawBits( int const raw ) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixedPointValue = raw;
}
