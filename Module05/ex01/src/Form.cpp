#include "Defines.hpp"
#include "Bureaucrat.hpp"
#include "Form.hpp"

/* Constructor Method */
Form::Form( void ) : _name("DefaultForm"), _gradeToSign(10), _gradeToExecute(10), _signed(false) {}

Form::Form( std::string name, int gradeToSign, int gradeToExecute ) : _name(name), _gradeToSign(gradeToSign), \
	_gradeToExecute(gradeToExecute), _signed(false) {
	if (gradeToSign < 1 || gradeToExecute < 1) {
		throw Form::GradeTooHighException();
	} else if (gradeToSign > 150 || gradeToExecute > 150) {
		throw Form::GradeTooLowException();
	} 
}

/* Copy Constructor Method */
Form::Form( const Form &other ) : _name(other.getName()), _gradeToSign(other.getGradeToSign()), \
	_gradeToExecute(other.getGradeToExecute()), _signed(other.getSigned()){
	*this = other;
}

/* Copy Assignment Operator Overload */
Form &Form::operator=( const Form &other ) {
	if ( this != &other ) {
		const_cast<std::string &>(this->_name) = other.getName();
		const_cast<int &>(this->_gradeToSign) = other.getGradeToSign();
		const_cast<int &>(this->_gradeToExecute) = other.getGradeToExecute();
		this->_signed = other.getSigned();
	}
	return (*this);
}

/* Destructor Method */
Form::~Form( void ) {};

 /* Public Methods */
std::string Form::getName( void ) const {
	return (this->_name);
}

int Form::getGradeToSign( void ) const {
	return (this->_gradeToSign);
}

int	Form::getGradeToExecute( void ) const {
	return (this->_gradeToExecute);
}

bool	Form::getSigned( void ) const {
	return (this->_signed);
}

void	Form::beSigned( const Bureaucrat &bureaucrat ) {
	if (bureaucrat.getGrade() > this->getGradeToSign()) {
		throw Form::GradeTooLowException();
	} else {
		this->_signed = true;
	}
}

/* Exception Classes */
const char *Form::GradeTooHighException::what() const throw() {
	return ("Form Grade is too high! Only 1-150 allowed.");
}

const char *Form::GradeTooLowException::what() const throw() {
	return ("Form Grade is too low! Only 1-150 allowed.");
}

/* Output Operator Overload */
std::ostream &operator<<( std::ostream &out, Form const &value ) {
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
