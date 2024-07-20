#include "Defines.hpp"
#include "PmergeMe.hpp"

namespace PMUtils {
	template <typename Container>
	void	verifyNegativeNumbers( Container &container ) {
		typename Container::iterator it = container.begin();

		while (it != container.end()) {
			if (*it < 0)
				throw NegativeNumberException();
			it++;
		}
	}
}

/* Constructor Method */
PmergeMe::PmergeMe( void ) { throw InvalidContainerException(); }

PmergeMe::PmergeMe( Vector vector ) : _vector(vector) {
	PMUtils::verifyNegativeNumbers(vector);
}

PmergeMe::PmergeMe( Deque deque ) : _deque(deque) {
	PMUtils::verifyNegativeNumbers(deque);
}

/* Copy Constructor Method */
PmergeMe::PmergeMe( const PmergeMe &other ) {
	*this = other;
}

/* Copy Assignment Operator Overload */
PmergeMe &PmergeMe::operator=( const PmergeMe &other ) {
	if ( this != &other ) {
		this->_vector = other._vector;
		this->_deque = other._deque;
	}
	return (*this);
}

/* Destructor Method */
PmergeMe::~PmergeMe( void ) {};

/* Vector Methods */
Vector	PmergeMe::fordJohnsonSort( const Vector &vector ) {
	// if (vector.empty())
	// 	throw InvalidVectorException();
	
	// if (vector.size() == 1)
	// 	return (vector);
	
	// Vector	left(vector.begin(), vector.begin() + vector.size() / 2);
	// Vector	right(vector.begin() + vector.size() / 2, vector.end());
	
	// left = fordJohnsonSort(left);
	// right = fordJohnsonSort(right);
	
	return (vector);
}



/* Deque Methods */
Deque	PmergeMe::fordJohnsonSort( const Deque &deque ) {
	// if (deque.empty())
	// 	throw InvalidDequeException();
	
	// if (deque.size() == 1)
	// 	return (deque);
	
	// Deque	left(deque.begin(), deque.begin() + deque.size() / 2);
	// Deque	right(deque.begin() + deque.size() / 2, deque.end());
	
	// left = fordJohnsonSort(left);
	// right = fordJohnsonSort(right);
	
	return (deque);
}

/* Exception Classes */
const char *InvalidContainerException::what( void ) const throw() {
	return (RED "Error: Enter a Valid Container." RESET);
}

const char *NegativeNumberException::what( void ) const throw() {
	return (RED "Error: Container Can Only Contain Positive Values." RESET);
}
