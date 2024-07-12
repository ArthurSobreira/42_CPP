#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include "Defines.hpp"
#include <algorithm>
#include <iostream>
#include <stdexcept>

template <typename T> 
typename T::iterator	easyfind( T const &container, int const value );

class ValueNotFoundException : public std::exception {
	public:
		virtual const char *what() const throw() {
			return (RED "Value Not Found in Container" RESET);
		}
};

#include "../src/easyfind.tpp"

#endif
