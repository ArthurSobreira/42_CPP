#include "Defines.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

/* Constructor Method */
Intern::Intern( void ) {};

/* Copy Constructor Method */
Intern::Intern( const Intern &other ) {
	*this = other;
}

/* Copy Assignment Operator Overload */
Intern &Intern::operator=( const Intern &other ) {
	(void)other;
	return (*this);
}

/* Destructor Method */
Intern::~Intern( void ) {}

/* Public Methods */
AForm	*Intern::makeForm( std::string formName, std::string target ) {
	std::string	formNames[3] = {"Robotomy Request", 
		"Presidential Pardon", "Shrubbery Creation"};

	short int i;
	for (i = 0; i < 3; i++) {
		if (formName == formNames[i]) break;
	}

	switch (i) {
		case 0:
			std::cout << "Intern creates " << COLORIZE(YELLOW, formName) \
			<< " Form." << std::endl;
			return (new RobotomyRequestForm(target));
		case 1:
			std::cout << "Intern creates " << COLORIZE(YELLOW, formName) \
			<< " Form." << std::endl;
			return (new PresidentialPardonForm(target));
		case 2:
			std::cout << "Intern creates " << COLORIZE(YELLOW, formName) \
			<< " Form." << std::endl;
			return (new ShrubberyCreationForm(target));
		default:
			throw Intern::FormNotFoundException();
	}
	return (NULL);
}

/* Exception Class */
const char *Intern::FormNotFoundException::what() const throw() {
	return ("Invalid Form Name! Only 'Robotomy Request', 'Presidential Pardon', \n\
	and 'Shrubbery Creation' are valid Form Names.");
}
