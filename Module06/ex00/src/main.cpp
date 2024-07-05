#include "Defines.hpp"
#include "ScalarConverter.hpp"

int main( int argc, char *argv[] ) {
	if (argc != 2) {
		std::cerr << COLORIZE(RED, " Usage: ") \
		<< argv[0] << " <value>" << std::endl;
		return (1);
	}

	ScalarConverter::convert(std::string(argv[1]));

	/* ScalarConverter converter;  // This will cause a compile error

	converter.convert(std::string(argv[1])); */

	return (0);
}
