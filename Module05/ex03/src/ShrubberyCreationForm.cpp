#include "Defines.hpp"
#include "ShrubberyCreationForm.hpp"
#include <fstream>

/* Constructor Method */
ShrubberyCreationForm::ShrubberyCreationForm( void ) : \
	AForm("ShrubberyCreationForm", 145, 137), _target("DefaultTarget") {};

ShrubberyCreationForm::ShrubberyCreationForm( std::string const target ) : \
	AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

/* Copy Constructor Method */
ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm &other ) : \
	AForm("ShrubberyCreationForm", 145, 137), _target(other.getTarget()) {
	*this = other;
}

/* Copy Assignment Operator Overload */
ShrubberyCreationForm &ShrubberyCreationForm::operator=( const ShrubberyCreationForm &other ) {
	if ( this != &other ) {
		AForm::operator=(other);
		const_cast<std::string &>(this->_target) = other.getTarget();
	}
	return (*this);
}

/* Destructor Method */
ShrubberyCreationForm::~ShrubberyCreationForm( void ) {}

 /* Public Methods */
std::string ShrubberyCreationForm::getTarget( void ) const {
	return (this->_target);
}

void	ShrubberyCreationForm::execute( Bureaucrat const &executor ) const {
	if (!this->getSigned()) {
		throw AForm::FormNotSignedException();
	} else if (executor.getGrade() > this->getGradeToExecute()) {
		throw AForm::GradeTooLowException();
	}

	const std::string	fileName = this->getTarget() + "_shrubbery";

	std::ofstream file(fileName.c_str());
	if (!file.is_open() || file.fail()) {
		throw std::runtime_error("Error: '" + fileName + "' Could Not be Opened.");
	}
	file << ASCII_TREE << std::endl;
	file.close();
}
