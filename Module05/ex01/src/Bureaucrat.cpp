#include "Defines.hpp"
#include "Form.hpp"
#include "Bureaucrat.hpp"

/* Constructor Methods */
Bureaucrat::Bureaucrat( void ) : _name("DefaultBureaucrat"), _grade(10) {}

Bureaucrat::Bureaucrat( const std::string name, int grade ) : _name(name) {
	if (grade < 1) {
		throw GradeTooHighException();
	} else if (grade > 150) {
		throw GradeTooLowException();
	} else {
		this->_grade = grade;
	}
}

/* Copy Constructor Method */
Bureaucrat::Bureaucrat( const Bureaucrat &other ) {
	*this = other;
}

/* Copy Assignment Operator Overload */
Bureaucrat &Bureaucrat::operator=( const Bureaucrat &other ) {
	if (this != &other) {
		const_cast<std::string &>(this->_name) = other.getName();
		this->_grade = other.getGrade();
	}
	return (*this);
}

/* Destructor Method */
Bureaucrat::~Bureaucrat( void ) {};

/* Public Methods */
std::string	Bureaucrat::getName( void ) const {
	return (this->_name);
}

int	Bureaucrat::getGrade( void ) const {
	return (this->_grade);
}

void	Bureaucrat::incrementGrade( void ) {
	if (this->getGrade() - 1 < 1) {
		throw GradeTooHighException();
	} else {
		this->_grade--;
	}
}

void	Bureaucrat::decrementGrade( void ) {
	if (this->getGrade() + 1 > 150) {
		throw GradeTooLowException();
	} else {
		this->_grade++;
	}
}

void	Bureaucrat::signForm( Form &form ) {
	if (this->getGrade() <= form.getGradeToSign()) {
		form.beSigned(*this);
		std::cout << COLORIZE(GREEN, this->getName()) << " signs " << \
		COLORIZE(GREEN, form.getName()) << std::endl;
	} else {
		std::cout << COLORIZE(RED, this->getName()) << " cannot sign " << \
		COLORIZE(RED, form.getName()) << " because " << COLORIZE(RED, "grade is too low") << std::endl;
	}
}

/* Exception Classes */
const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade is too high! Only 1-150 allowed.");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade is too low! Only 1-150 allowed.");
}

/* Output Operator Overload */
std::ostream &operator<<( std::ostream &out, Bureaucrat const &value ) {
	out << COLORIZE(CYAN, value.getName()) << ", bureaucrat grade " << \
	COLORIZE(YELLOW, value.getGrade());
	return (out);
}
