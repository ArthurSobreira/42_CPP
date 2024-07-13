#ifndef SPAN_HPP
#define SPAN_HPP

typedef unsigned int	uint;

#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>

class Span {
	private:
		std::vector<int>	_list;
		uint	_size;
		
	public:
		/* Constructor Methods */
		Span( void );
		Span( uint size );
		
		/* Copy Constructor Method */
		Span( const Span &other );
		
		/* Copy Assignment Operator Overload */
		Span &operator=( const Span &other );
		
		/* Destructor Method */
		~Span( void );
		
		/* Public Methods */
		void	addNumber( int number );
		int		shortestSpan( void );
		int		longestSpan( void );
		void	populate( std::vector<int>::iterator begin, 
			std::vector<int>::iterator end );

		/* Exception Classes */
		class LimitReachedException : public std::exception {
			public:
				virtual const char *what( void ) const throw();
		};

		class NotEnoughNumbersException : public std::exception {
			public:
				virtual const char *what( void ) const throw();
		};
};

#endif
