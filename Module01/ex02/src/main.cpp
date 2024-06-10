#include "Defines.hpp"
#include <iostream>

int	main ( void ) {
	std::string	string = "HI THIS IS BRAIN";
	std::string	*stringPTR = &string;
	std::string	&stringREF = string;

	std::cout << "Address of the string: " << &string << std::endl;
	std::cout << "Address of the string: " << stringPTR << std::endl;
	std::cout << "Address of the string: " << &stringREF << std::endl;
	std::cout << "String value: " << string << std::endl;
	std::cout << "String value: " << *stringPTR << std::endl;
	std::cout << "String value: " << stringREF << std::endl;

	return (0);
}
