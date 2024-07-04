#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter {
	private:
		/* Constructor Method */
		ScalarConverter( void );
		
		/* Copy Constructor Method */
		ScalarConverter( const ScalarConverter &other );
		
		/* Copy Assignment Operator Overload */
		ScalarConverter &operator=( const ScalarConverter &other );
		
		/* Destructor Method */
		~ScalarConverter( void );

	public:
		static void	convert( std::string const &value );

		/* Exception Classes */
		class NonDisplayableException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class ImpossibleException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

#endif
