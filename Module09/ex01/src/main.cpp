#include "Defines.hpp"
#include "RPN.hpp"

int main( int argc, char *argv[] ) {
	if (argc != 2) {
		std::cout << COLORIZE(RED, "Usage: ./RPN [expression]") << std::endl;
		return (1);
	}

	std::string	expression(argv[1]);

	try {
		RPN	rpn(expression);

		std::cout << rpn.calculate() << std::endl;
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
		return (1);
	}

	return (0);
}
