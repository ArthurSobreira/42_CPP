#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

/* Template Iter Function */
template <typename T>
void	iter( T *array, size_t length, void (*func)( T const& ) ) {
	if ( array == NULL || func == NULL ) {
		return ;
	}
	for ( size_t i = 0; i < length; i++ )
		func( array[i] );
}

/* Template Print Function */
template <typename T>
void	print( T const &value ) {
	std::cout << value << std::endl;
}

#endif
