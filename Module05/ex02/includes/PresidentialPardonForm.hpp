#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <iostream>

class PresidentialPardonForm : public AForm {
	private:
		std::string const _target;
		
	public:
		/* Constructor Method */
		PresidentialPardonForm( void );
		PresidentialPardonForm( std::string const target );

		/* Copy Constructor Method */
		PresidentialPardonForm( const PresidentialPardonForm &other );
		
		/* Copy Assignment Operator Overload */
		PresidentialPardonForm &operator=( const PresidentialPardonForm &other );
		
		/* Destructor Method */
		~PresidentialPardonForm( void );
		
		/* Public Methods */
		std::string getTarget( void ) const;
		void        execute( Bureaucrat const &executor ) const;
};

#endif
