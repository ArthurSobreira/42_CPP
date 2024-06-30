#include "Defines.hpp"
#include "PresidentialPardonForm.hpp"

/* Constructor Method */
PresidentialPardonForm::PresidentialPardonForm( void ) : \
	AForm("PresidentialPardonForm", 25, 5), _target("DefaultTarget") {};

PresidentialPardonForm::PresidentialPardonForm( std::string const target ) : \
	AForm("PresidentialPardonForm", 25, 5), _target(target) {}

/* Copy Constructor Method */
PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm &other ) : \
	AForm("PresidentialPardonForm", 25, 5), _target(other.getTarget()) {
	*this = other;
}

/* Copy Assignment Operator Overload */
PresidentialPardonForm &PresidentialPardonForm::operator=( const PresidentialPardonForm &other ) {
	if ( this != &other ) {
		AForm::operator=(other);
		const_cast<std::string &>(this->_target) = other.getTarget();
	}
	return (*this);
}

/* Destructor Method */
PresidentialPardonForm::~PresidentialPardonForm( void ) {}

 /* Public Methods */
std::string PresidentialPardonForm::getTarget( void ) const {
	return (this->_target);
}

void PresidentialPardonForm::execute( Bureaucrat const &executor ) const {
	if (!this->getSigned()) {
		throw AForm::FormNotSignedException();
	} else if (executor.getGrade() > this->getGradeToExecute()) {
		throw AForm::GradeTooLowException();
	}
	std::cout << COLORIZE(CYAN, this->getTarget()) << \
	" has been pardoned by Zaphod Beeblebrox." << std::endl;
}
