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
		Array( uint n );
		
		/* Copy Constructor Method */
		Array( const Array &other );
		
		/* Destructor Method */
		~Array( void );

		/* Operator Overloading */
		Array &operator=( const Array &other );
		T &operator[]( uint index ) const ;
		
		/* Public Methods */
		uint	size( void ) const;

		/* Exception Classes */
		class EmptyArrayException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class OutOfLimitsException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

#include "../src/Array.tpp"

#endif
