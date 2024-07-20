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
		
		/* Vector Methods */
		Vector	fordJohnsonSort( const Vector &vector );
		Vector	merge( const Vector &left, const Vector &right );
		void	insetion( Vector &vector );

		/* Deque Methods */
		Deque	fordJohnsonSort( const Deque &deque );
		Deque	merge( const Deque &left, const Deque &right );
		void	insetion( Deque &deque );
};

/* Exception Classes */
class InvalidVectorException : public std::exception {
	public:
		virtual const char *what( void ) const throw();
};

class InvalidDequeException : public std::exception {
	public:
		virtual const char *what( void ) const throw();
};

#endif
