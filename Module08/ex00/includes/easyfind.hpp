#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iostream>
#include <stdexcept>

template <typename T> 
T::iterator	easyfind( T const &container, int const value );

class ValueNotFoundException : public std::exception {
	public:
		virtual const char *what() const throw();
};

#include "../src/easyfind.tpp"

#endif
