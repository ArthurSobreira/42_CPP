#include "Form.hpp"
#include "Bureaucrat.hpp"

/* Constructor Method */
Form::Form( void ) : _name("DefaultForm"), \
	_gradeToSign(10), _gradeToExecute(10), _signed(false) {}

Form::Form( std::string name, int gradeToSign, int gradeToExecute ) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _signed(false) {
	// if (gradeToSign < 1 || gradeToExecute < 1) {
	// 	throw GradeTooHighException();
	// } else if (gradeToSign > 150 || gradeToExecute > 150) {
	// 	throw GradeTooLowException();
	// } 
}

/* Copy Constructor Method */
Form::Form( const Form &other ) {
	*this = other;
}

/* Copy Assignment Operator Overload */
Form &Form::operator=( const Form &other ) {
	if ( this != &other ) {
		this->_name = other.getName();
		this->_gradeToSign = other.getGradeToSign();
		this->_gradeToExecute = other.getGradeToExecute();
		this->_signed = other.getSigned();
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
