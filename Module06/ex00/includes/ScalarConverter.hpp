#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter {
	private:
		int attribute;
		
	public:
		/* Constructor Method */
		ScalarConverter( void );
		
		/* Copy Constructor Method */
		ScalarConverter( const ScalarConverter &other );
		
		/* Copy Assignment Operator Overload */
		ScalarConverter &operator=( const ScalarConverter &other );
		
		/* Destructor Method */
		~ScalarConverter( void );
		
		/* Public Methods */
		int    getAttribute( void ) const;
		void   setAttribute( int value );
		
};

#endif
