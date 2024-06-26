#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <stdexcept>

class Bureaucrat;

class Form {
	private:
		std::string const _name;
		int const	_gradeToSign;
		int const	_gradeToExecute;
		bool 		_signed;
		
	public:
		/* Constructor Method */
		Form( void );
		Form( std::string name, int gradeToSign, int gradeToExecute);
		
		/* Copy Constructor Method */
		Form( const Form &other );
		
		/* Copy Assignment Operator Overload */
		Form &operator=( const Form &other );
		
		/* Destructor Method */
		~Form( void );
		
		/* Public Methods */
		std::string getName( void ) const;
		int		getGradeToSign( void ) const;
		int		getGradeToExecute( void ) const;
		bool	getSigned( void ) const;
		void	beSigned( const Bureaucrat &bureaucrat );

		/* Exception Classes */
		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

/* Output Operator Overload */
std::ostream &operator<<( std::ostream &out, Form const &value );

#endif
