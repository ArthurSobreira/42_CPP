#include "easyfind.hpp"

template <typename T>
typename T::iterator	easyfind( T const &container, int const value ) {
	typename T::iterator	occ;

	occ = std::find(container.begin(), container.end(), value);
	if (occ == container.end()) {
		throw ValueNotFoundException();
	}
	return (occ);
}
