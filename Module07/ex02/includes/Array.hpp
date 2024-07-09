#ifndef ARRAY_HPP
#define ARRAY_HPP

typedef unsigned int	uint;

template <typename T> class Array {
	private:
		T		*_array;
		uint	_size;
		
	public:
		/* Constructor Method */
		Array( void );
		Array( uint n )
		
		/* Copy Constructor Method */
		Array( const Array &other );
		
		/* Copy Assignment Operator Overload */
		Array &operator=( const Array &other );
		
		/* Destructor Method */
		~Array( void );
		
		/* Public Methods */
		uint	size( void ) const;
		T &operator[]( uint index );
};

#include "../src/Array.tpp"

#endif
