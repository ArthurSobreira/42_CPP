#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <stdexcept>

class Bureaucrat;

class AForm {
	private:
		std::string const _name;
		int const	_gradeToSign;
		int const	_gradeToExecute;
		bool 		_signed;
		
	public:
		/* Constructor Method */
		AForm( void );
		AForm( std::string name, int gradeToSign, int gradeToExecute);
		
		/* Copy Constructor Method */
		AForm( const AForm &other );
		
		/* Copy Assignment Operator Overload */
		AForm &operator=( const AForm &other );
		
		/* Destructor Method */
		virtual ~AForm( void );
		
		/* Public Methods */
		std::string getName( void ) const;
		int		getGradeToSign( void ) const;
		int		getGradeToExecute( void ) const;
		bool	getSigned( void ) const;
		void	beSigned( const Bureaucrat &bureaucrat );
		virtual void execute( Bureaucrat const &executor ) const = 0;

		/* Exception Classes */
		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class FormNotSignedException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

/* Output Operator Overload */
std::ostream &operator<<( std::ostream &out, AForm const &value );

#endif
