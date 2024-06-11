#ifndef FIXEDOPERATORS_HPP
# define FIXEDOPERATORS_HPP

#include "Fixed.hpp"

/* Comparison Operators */
bool	Fixed::operator>(Fixed const &other) const {
	return (this->_fixedPointValue > other.getRawBits());
}

bool	Fixed::operator<(Fixed const &other) const {
	return (this->_fixedPointValue < other.getRawBits());
}

#endif