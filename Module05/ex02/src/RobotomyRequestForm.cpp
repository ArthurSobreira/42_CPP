#include "Defines.hpp"
#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

/* Constructor Method */
RobotomyRequestForm::RobotomyRequestForm( void ) : \
	AForm("RobotomyRequestForm", 72, 45), _target("DefaultTarget") {};

RobotomyRequestForm::RobotomyRequestForm( std::string const target ) : \
	AForm("RobotomyRequestForm", 72, 45), _target(target) {}

/* Copy Constructor Method */
RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm &other ) : \
	AForm("RobotomyRequestForm", 72, 45), _target(other.getTarget()) {
	*this = other;
}

/* Copy Assignment Operator Overload */
RobotomyRequestForm &RobotomyRequestForm::operator=( const RobotomyRequestForm &other ) {
	if ( this != &other ) {
		AForm::operator=(other);
		const_cast<std::string &>(this->_target) = other.getTarget();
	}
	return (*this);
}

/* Destructor Method */
RobotomyRequestForm::~RobotomyRequestForm( void ) {}

/* Public Methods */
std::string RobotomyRequestForm::getTarget( void ) const {
	return (this->_target);
}

void RobotomyRequestForm::execute( Bureaucrat const &executor ) const {
	if (!this->getSigned()) {
		throw AForm::FormNotSignedException();
	} else if (executor.getGrade() > this->getGradeToExecute()) {
		throw AForm::GradeTooLowException();
	}
	std::cout << COLORIZE(MAGENTA, " ~ Some Drilling Noises ~ ") << std::endl;
	srand(static_cast<unsigned int>(time(NULL)));
	if (rand() % 2) {
		std::cout << COLORIZE(CYAN, this->getTarget()) << " has been robotomized successfully!" << std::endl;
	} else {
		std::cout << COLORIZE(CYAN, this->getTarget()) << " has failed to be robotomized!" << std::endl;
	}
}
