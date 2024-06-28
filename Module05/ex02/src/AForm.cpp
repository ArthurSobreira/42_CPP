#include "Defines.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

/* Constructor Method */
AForm::AForm( void ) : _name("DefaultAForm"), _gradeToSign(10), _gradeToExecute(10), _signed(false) {}

AForm::AForm( std::string name, int gradeToSign, int gradeToExecute ) : _name(name), _gradeToSign(gradeToSign), \
	_gradeToExecute(gradeToExecute), _signed(false) {
	if (gradeToSign < 1 || gradeToExecute < 1) {
		throw AForm::GradeTooHighException();
	} else if (gradeToSign > 150 || gradeToExecute > 150) {
		throw AForm::GradeTooLowException();
	} 
}

/* Copy Constructor Method */
AForm::AForm( const AForm &other ) : _name(other.getName()), _gradeToSign(other.getGradeToSign()), \
	_gradeToExecute(other.getGradeToExecute()), _signed(other.getSigned()){
	*this = other;
}

/* Copy Assignment Operator Overload */
AForm &AForm::operator=( const AForm &other ) {
	if ( this != &other ) {
		const_cast<std::string &>(this->_name) = other.getName();
		const_cast<int &>(this->_gradeToSign) = other.getGradeToSign();
		const_cast<int &>(this->_gradeToExecute) = other.getGradeToExecute();
		this->_signed = other.getSigned();
	}
	return (*this);
}

/* Destructor Method */
AForm::~AForm( void ) {};

 /* Public Methods */
std::string AForm::getName( void ) const {
	return (this->_name);
}

int AForm::getGradeToSign( void ) const {
	return (this->_gradeToSign);
}

int	AForm::getGradeToExecute( void ) const {
	return (this->_gradeToExecute);
}

bool	AForm::getSigned( void ) const {
	return (this->_signed);
}

void	AForm::beSigned( const Bureaucrat &bureaucrat ) {
	if (bureaucrat.getGrade() > this->getGradeToSign()) {
		throw AForm::GradeTooLowException();
	} else {
		this->_signed = true;
	}
}

/* Exception Classes */
const char *AForm::GradeTooHighException::what() const throw() {
	return ("Form Grade is too high! Only 1-150 allowed.");
}

const char *AForm::GradeTooLowException::what() const throw() {
	return ("Form Grade is too low! Only 1-150 allowed.");
}

/* Output Operator Overload */
std::ostream &operator<<( std::ostream &out, AForm const &value ) {
    out << "Form Name: " <<  COLORIZE(CYAN, value.getName()) << \
    " | Grade to Sign: " <<  COLORIZE(YELLOW, value.getGradeToSign()) << \
    " | Grade to Execute: " << COLORIZE(YELLOW, value.getGradeToExecute()) << \
    " | Signed: ";
	if (value.getSigned()) {
		out << COLORIZE(GREEN, "true");
	} else {
		out << COLORIZE(RED, "false");
	}
	return (out);
}
