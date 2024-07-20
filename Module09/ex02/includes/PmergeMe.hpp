#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <iomanip>
#include <ctime>
#include <vector>
#include <deque>

typedef std::vector<int>	Vector;
typedef std::deque<int>		Deque;

class PmergeMe {
	private:
		Vector	_vector;
		Deque	_deque;
		
	public:
		/* Constructor Methods */
		PmergeMe( void );
		PmergeMe( Vector vector );
		PmergeMe( Deque deque );
		
		/* Copy Constructor Method */
		PmergeMe( const PmergeMe &other );
		
		/* Copy Assignment Operator Overload */
		PmergeMe &operator=( const PmergeMe &other );
		
		/* Destructor Method */
		~PmergeMe( void );
		
		/* Vector Method */
		Vector	fordJohnsonSort( const Vector &vector );

		/* Deque Method */
		Deque	fordJohnsonSort( const Deque &deque );
};

/* Exception Classes */
class InvalidContainerException : public std::exception {
	public:
		virtual const char *what( void ) const throw();
};

class NegativeNumberException : public std::exception {
	public:
		virtual const char *what( void ) const throw();
};

#endif
