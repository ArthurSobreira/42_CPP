#include "Data.hpp"

/* Constructor Method */
Data::Data( void ) : _attribute(10) {};

Data::Data( int attribute ) : _attribute(attribute) {};

/* Copy Constructor Method */
Data::Data( const Data &other ) {
	*this = other;
}

/* Copy Assignment Operator Overload */
Data &Data::operator=( const Data &other ) {
	if ( this != &other ) {
		this->_attribute = other.getAttribute();
	}
	return (*this);
}

/* Destructor Method */
Data::~Data( void ) {}

 /* Public Methods */
int Data::getAttribute( void ) const {
	return (this->_attribute);
}
