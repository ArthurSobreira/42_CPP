#include "Defines.hpp"
#include "Array.hpp"

/* Constructor Methods */
template <typename T> 
Array<T>::Array( void ) : _array(NULL), _size(0) {}

template <typename T> 
Array<T>::Array( uint n ) : _array(NULL), _size(n) {
	if (n == 0) {
		return ;
	}
	this->_array = new T[n];
	for (uint i = 0; i < n; i++) {
		this->_array[i] = T();
	}
}

/* Copy Constructor Method */
template <typename T> 
Array<T>::Array( const Array &other ) : _array(NULL), _size(0) {
	*this = other;
}

/* Destructor Method */
template <typename T> 
Array<T>::~Array( void ) {
	if (this->_array != NULL) {
		delete[] this->_array;
	}
}

/* Operator Overloading */
template <typename T> 
Array<T> &Array<T>::operator=( const Array &other ) {
	if (this != &other) {
		this->_size = other._size;
		if (this->_array != NULL) {
			delete[] this->_array;
		}
		if (other._array != NULL) {
			this->_array = new T[this->_size];
			for (uint i = 0; i < this->_size; i++) {
				this->_array[i] = other._array[i];
			}
		} else {
			this->_array = NULL;
		}
	}
	return (*this);
}

template <typename T>
T &Array<T>::operator[]( uint index ) const {
	if (this->_array == NULL) {
		throw EmptyArrayException();
	}
	if (index >= this->_size) {
		throw OutOfLimitsException();
	}
	return (this->_array[index]);
}

/* Public Methods */
template <typename T> 
uint Array<T>::size( void ) const {
	return (this->_size);
}

/* Exception Classes */
template <typename T>
const char *Array<T>::EmptyArrayException::what() const throw() {
	return (RED "Array is empty" RESET);
}

template <typename T>
const char *Array<T>::OutOfLimitsException::what() const throw() {
	return (RED "Index out of limits" RESET);
}
