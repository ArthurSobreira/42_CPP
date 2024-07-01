#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	private:
		std::string const _target;
		
	public:
		/* Constructor Method */
		RobotomyRequestForm( void );
		RobotomyRequestForm( std::string const target );
		
		/* Copy Constructor Method */
		RobotomyRequestForm( const RobotomyRequestForm &other );
		
		/* Copy Assignment Operator Overload */
		RobotomyRequestForm &operator=( const RobotomyRequestForm &other );
		
		/* Destructor Method */
		~RobotomyRequestForm( void );
		
		/* Public Methods */
		std::string getTarget( void ) const;
		void        execute( Bureaucrat const &executor ) const;
};

#endif
