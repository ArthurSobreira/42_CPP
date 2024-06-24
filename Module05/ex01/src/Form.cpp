#include "Form.hpp"

/* Constructor Method */
Form::Form( void ) {};

/* Copy Constructor Method */
Form::Form( const Form &other ) {
	*this = other;
}

/* Copy Assignment Operator Overload */
Form &Form::operator=( const Form &other ) {
	if ( this != &other ) {
		this->attribute = other.getAttribute();
	}
	return *this;
}

/* Destructor Method */
Form::~Form( void ) {}

 /* Public Methods */
int Form::getAttribute( void ) const {
	return this->attribute;
}

void Form::setAttribute( int value ) {
	this->attribute = value;
}