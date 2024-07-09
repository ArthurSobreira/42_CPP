#ifndef ARRAY_HPP
#define ARRAY_HPP

typedef unsigned int	uint;

#include <iostream>
#include <stdexcept>

template <typename T> class Array {
	private:
		T		*_array;
		uint	_size;
		
	public:
		/* Constructor Methods */
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

		/* Exception Classes */
		class OutOfLimitsException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class EmptyArrayException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

#include "../src/Array.tpp"

#endif
