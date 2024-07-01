#include "ScalarConverter.hpp"

/* Constructor Method */
ScalarConverter::ScalarConverter( void ) {};

/* Copy Constructor Method */
ScalarConverter::ScalarConverter( const ScalarConverter &other ) {
	*this = other;
}

/* Copy Assignment Operator Overload */
ScalarConverter &ScalarConverter::operator=( const ScalarConverter &other ) {
	(void)other;
	return (*this);
}

/* Destructor Method */
ScalarConverter::~ScalarConverter( void ) {}

 /* Public Methods */
void	ScalarConverter::convert( std::string const &value ) {
	std::cout << "Value: " << value << std::endl;
}
