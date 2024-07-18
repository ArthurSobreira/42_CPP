#include "Defines.hpp"
#include "BitcoinExchange.hpp"

int main( int argc, char *argv[] ) {
	if (argc != 2) {
		std::cout << COLORIZE(RED, "Usage: ./bitcoin [filename]") << std::endl;
		return (1);
	}
	std::string	filename(argv[1]);

	BitcoinExchange	btc(filename);
	std::cout << std::setprecision(15) << 
	btc.getDatabase()["2022-03-29"] << std::endl;
	return (0);
}
