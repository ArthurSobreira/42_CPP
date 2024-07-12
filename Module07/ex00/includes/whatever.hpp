#ifndef WHATEVER_HPP
#define WHATEVER_HPP

/* Template Swap Function */
template <typename T> void	swap( T &a, T &b ) {
	T temp = a;
	a = b;
	b = temp;
}

/* Template Min and Max Functions */
template <typename T> T	min( T const &a, T const &b ) {
	return ( a < b ? a : b );
}

template <typename T> T	max( T const &a, T const &b ) {
	return ( ::min( a, b ) == a ? b : a );
}

#endif
