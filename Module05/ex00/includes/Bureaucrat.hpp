#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>

class Bureaucrat {
	private:
		std::string const _name;
		int	_grade;
		
	public:
		/* Constructor Method */
		Bureaucrat( void );
		Bureaucrat( const std::string name, int grade );
		
		/* Copy Constructor Method */
		Bureaucrat( const Bureaucrat &other );
		
		/* Copy Assignment Operator Overload */
		Bureaucrat &operator=( const Bureaucrat &other );
		
		/* Destructor Method */
		~Bureaucrat( void );
		
		/* Public Methods */
		std::string	getName( void ) const;
		int			getGrade( void ) const;
		void		incrementGrade( void );
		void		decrementGrade( void );

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

std::ostream &operator<<( std::ostream &out, Bureaucrat const &value );

#endif
