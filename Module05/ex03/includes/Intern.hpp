#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include <iostream>

class Intern {
	public:
		/* Constructor Method */
		Intern( void );
		
		/* Copy Constructor Method */
		Intern( const Intern &other );
		
		/* Copy Assignment Operator Overload */
		Intern &operator=( const Intern &other );
		
		/* Destructor Method */
		~Intern( void );
		
		/* Public Methods */
		AForm	*makeForm( std::string formName, std::string target );
};

#endif
