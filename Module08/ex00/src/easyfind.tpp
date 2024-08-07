#include "easyfind.hpp"

/* Template easyfind Function */
template <typename T>
typename T::iterator	easyfind( T &container, int value ) {
	typename T::iterator	occ;

	occ = std::find(container.begin(), container.end(), value);
	if (occ == container.end()) {
		throw ValueNotFoundException();
	}
	return (occ);
}
