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

	void	insetion( Vector &vector ) {
		if (vector.size() < 2)
			return ;

		Vector::value_type	temp = vector[1];

		if (vector[0] > temp) {
			vector[1] = vector[0];
			vector[0] = temp;
		}
	}

	Vector	merge( const Vector &left, const Vector &right ) {
		Vector	result;
		Vector::size_type	i = 0, j = 0;

		while (i < left.size() && j < right.size()) {
			if (left[i] < right[j])
				result.push_back(left[i++]);
			else
				result.push_back(right[j++]);
		}
		while (i < left.size())
			result.push_back(left[i++]);
		while (j < right.size())
			result.push_back(right[j++]);
		return (result);
	}

	void	insetion( Deque &deque ) {
		if (deque.size() < 2)
			return ;

		Deque::value_type	temp = deque[1];

		if (deque[0] > temp) {
			deque[1] = deque[0];
			deque[0] = temp;
		}
	}

	Deque	merge( const Deque &left, const Deque &right ) {
		Deque	result;
		Deque::size_type	i = 0, j = 0;

		while (i < left.size() && j < right.size()) {
			if (left[i] < right[j])
				result.push_back(left[i++]);
			else
				result.push_back(right[j++]);
		}
		while (i < left.size())
			result.push_back(left[i++]);
		while (j < right.size())
			result.push_back(right[j++]);
		return (result);
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

/* Vector Method */
Vector	PmergeMe::fordJohnsonSort( const Vector &vector ) {
	if (vector.size() < 2)
		return vector;

	Vector::size_type	subsetSize = 2;
	std::vector<Vector>	subsets;

	for (Vector::size_type i = 0; i < vector.size(); i += subsetSize) {
		Vector	subset(vector.begin() + i, vector.begin() + 
			std::min(i + subsetSize, vector.size()));

		PMUtils::insetion(subset);
		subsets.push_back(subset);		
	}

	while (subsets.size() > 1) {
		std::vector<Vector>	newSubsets;
		for (Vector::size_type i = 0; i < subsets.size(); i += subsetSize) {
			if (i + 1 < subsets.size()) {
				newSubsets.push_back(PMUtils::merge(subsets[i], subsets[i + 1]));
			} else {
				newSubsets.push_back(subsets[i]);
			}
		}
		subsets = newSubsets;
	}
	return (subsets[0]);
}

/* Deque Method */
Deque	PmergeMe::fordJohnsonSort( const Deque &deque ) {
	if (deque.size() < 2)
		return (deque);

	Deque::size_type	subsetSize = 2;
	std::vector<Deque>	subsets;

	for (Deque::size_type i = 0; i < deque.size(); i += subsetSize) {
		Deque	subset(deque.begin() + i, deque.begin() + 
			std::min(i + subsetSize, deque.size()));

		PMUtils::insetion(subset);
		subsets.push_back(subset);		
	}

	while (subsets.size() > 1) {
		std::vector<Deque>	newSubsets;
		for (Deque::size_type i = 0; i < subsets.size(); i += 2) {
			if (i + 1 < subsets.size()) {
				newSubsets.push_back(PMUtils::merge(subsets[i], subsets[i + 1]));
			} else {
				newSubsets.push_back(subsets[i]);
			}
		}
		subsets = newSubsets;
	}
	return (subsets[0]);
}

/* Exception Classes */
const char *InvalidContainerException::what( void ) const throw() {
	return (RED "Error: Enter a Valid Container." RESET);
}

const char *NegativeNumberException::what( void ) const throw() {
	return (RED "Error: Container Can Only Contain Positive Values." RESET);
}
