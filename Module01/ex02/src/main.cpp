#include "Defines.hpp"
#include <iostream>

int	main ( void ) {
	std::string	string = "HI THIS IS BRAIN";
	std::string	*stringPTR = &string;
	std::string	&stringREF = string;

	std::cout << YELLOW << "Address of the string: " <<
		RESET << &string << std::endl;
	std::cout << YELLOW << "Address of the string: " <<
		RESET << stringPTR << std::endl;
	std::cout << YELLOW << "Address of the string: " <<
		RESET << &stringREF << std::endl;
	
	std::cout << CYAN << "String value: " <<
		RESET << string << std::endl;
	std::cout << CYAN << "String value: " <<
		RESET << *stringPTR << std::endl;
	std::cout << CYAN << "String value: " <<
		RESET << stringREF << std::endl;

	return (0);
}
