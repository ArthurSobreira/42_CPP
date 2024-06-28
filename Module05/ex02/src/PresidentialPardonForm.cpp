#include "PresidentialPardonForm.hpp"

/* Constructor Method */
PresidentialPardonForm::PresidentialPardonForm( void ) : \
	AForm("PresidentialPardonForm", 25, 5), _target("DefaultTarget") {};

PresidentialPardonForm::PresidentialPardonForm( std::string const target ) : \
	AForm("PresidentialPardonForm", 25, 5), _target(target) {}

/* Copy Constructor Method */
PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm &other ) {
	*this = other;
}

/* Copy Assignment Operator Overload */
PresidentialPardonForm &PresidentialPardonForm::operator=( const PresidentialPardonForm &other ) {
	if ( this != &other ) {
		this->attribute = other.getAttribute();
	}
	return (*this);
}

/* Destructor Method */
PresidentialPardonForm::~PresidentialPardonForm( void ) {}

 /* Public Methods */
int PresidentialPardonForm::getAttribute( void ) const {
	return (this->attribute);
}

void PresidentialPardonForm::setAttribute( int value ) {
	this->attribute = value;
}