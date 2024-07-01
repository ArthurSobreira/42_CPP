#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <iostream>

class ShrubberyCreationForm : public AForm {
	private:
		std::string const _target;
		
	public:
		/* Constructor Method */
		ShrubberyCreationForm( void );
		ShrubberyCreationForm( std::string const target );

		/* Copy Constructor Method */
		ShrubberyCreationForm( const ShrubberyCreationForm &other );
		
		/* Copy Assignment Operator Overload */
		ShrubberyCreationForm &operator=( const ShrubberyCreationForm &other );
		
		/* Destructor Method */
		~ShrubberyCreationForm( void );
		
		/* Public Methods */
		std::string getTarget( void ) const;
		void        execute( Bureaucrat const &executor ) const;
};

#endif
