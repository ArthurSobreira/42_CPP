#include "ScalarConverter.hpp"

/* Constructor Method */
ScalarConverter::ScalarConverter( void ) {};

/* Copy Constructor Method */
ScalarConverter::ScalarConverter( const ScalarConverter &other ) {
	*this = other;
}

/* Copy Assignment Operator Overload */
ScalarConverter &ScalarConverter::operator=( const ScalarConverter &other ) {
	if ( this != &other ) {
		this->attribute = other.getAttribute();
	}
	return (*this);
}

/* Destructor Method */
ScalarConverter::~ScalarConverter( void ) {}

 /* Public Methods */
int ScalarConverter::getAttribute( void ) const {
	return (this->attribute);
}

void ScalarConverter::setAttribute( int value ) {
	this->attribute = value;
}