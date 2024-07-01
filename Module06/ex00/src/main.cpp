#include "Defines.hpp"
#include "ScalarConverter.hpp"

int main( void ) {
	ScalarConverter sc;

	sc.setAttribute(42);
	std::cout << "Attribute: " << sc.getAttribute() << std::endl;

	return (0);
}
