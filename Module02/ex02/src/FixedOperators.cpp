#ifndef FIXEDOPERATORS_HPP
# define FIXEDOPERATORS_HPP

#include "Fixed.hpp"

/* Comparison Operators */
bool	Fixed::operator>( Fixed const &other ) const {
	return (this->getRawBits() > other.getRawBits());
}

bool	Fixed::operator<( Fixed const &other ) const {
	return (this->getRawBits() < other.getRawBits());
}

bool	Fixed::operator>=( Fixed const &other ) const {
	return (this->getRawBits() >= other.getRawBits());
}

bool	Fixed::operator<=( Fixed const &other ) const {
	return (this->getRawBits() <= other.getRawBits());
}

bool	Fixed::operator==( Fixed const &other ) const {
	return (this->getRawBits() == other.getRawBits());
}

bool	Fixed::operator!=( Fixed const &other ) const {
	return (this->getRawBits() != other.getRawBits());
}


/* Arithmetic Operators */
Fixed	Fixed::operator+( Fixed const &other ) const {
	return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed	Fixed::operator-( Fixed const &other ) const {
	return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed	Fixed::operator*( Fixed const &other ) const {
	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed	Fixed::operator/( Fixed const &other ) const {
	return (Fixed(this->toFloat() / other.toFloat()));
}


/* Increment and Decrement Operators */
Fixed	&Fixed::operator++( void ) {
	this->_fixedPointValue += 1;
	return (*this);
}

Fixed	Fixed::operator++( int ) {
	Fixed tmp(*this);
	++(*this);
	return (tmp);
}

Fixed	&Fixed::operator--( void ) {
	this->_fixedPointValue -= 1;
	return (*this);
}

Fixed	Fixed::operator--( int ) {
	Fixed tmp(*this);
	--(*this);
	return (tmp);
}


/* Min and Max Operators */
Fixed	&Fixed::min( Fixed &a, Fixed &b ) {
	return (a < b ? a : b);
}

Fixed	&Fixed::max( Fixed &a, Fixed &b ) {
	return (a > b ? a : b);
}

Fixed const	&Fixed::min( Fixed const &a, Fixed const &b ) {
	return (a < b ? a : b);
}

Fixed const &Fixed::max( Fixed const &a, Fixed const &b ) {
	return (a > b ? a : b);
}

#endif
