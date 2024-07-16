#include "MutantStack.hpp"

/* Constructor Method */
template <typename T>
MutantStack<T>::MutantStack( void ) : std::stack<T>() {};

/* Copy Constructor Method */
template <typename T>
MutantStack<T>::MutantStack( const MutantStack &other ) : std::stack<T>() {
	*this = other;
}

/* Copy Assignment Operator Overload */
template <typename T>
MutantStack<T> &MutantStack<T>::operator=( const MutantStack &other ) {
	if ( this != &other ) {
		std::stack<T>::operator=(other);
	}
	return (*this);
}

/* Destructor Method */
template <typename T>
MutantStack<T>::~MutantStack( void ) {}

/* Iterator Methods */
template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin( void ) {
	return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end( void ) {
	return (this->c.end());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin( void ) const {
	return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end( void ) const {
	return (this->c.end());
}
