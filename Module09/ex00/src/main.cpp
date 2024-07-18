#include "Defines.hpp"
#include "BitcoinExchange.hpp"

int main( int argc, char *argv[] ) {
	if (argc != 2) {
		std::cout << COLORIZE(RED, "Usage: ./bitcoin [filename]") << std::endl;
		return (1);
	}

	std::string	filename(argv[1]);
	BitcoinExchange	btc(filename);

	try {
		btc.exchangeRate();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		return (1);
	}

	return (0);
}
