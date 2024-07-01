#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include <iostream>
#include <stdexcept>

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

		/* Exception Class */
		class FormNotFoundException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

#endif
