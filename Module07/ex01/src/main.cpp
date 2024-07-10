#include "Defines.hpp"
#include "iter.hpp"
#include <string>

namespace Utils {
	void	invertCase( std::string const &str ) {
		std::string &copy = const_cast<std::string &>(str);
		for (size_t i = 0; i < copy.length(); i++) {
			if (std::isupper(copy[i])) {
				copy[i] = std::tolower(copy[i]);
			} else if (std::islower(copy[i])) {
				copy[i] = std::toupper(copy[i]);
			}
		}
	}

	void	isEven( int const &n ) {
		std::cout << n << " is ";
		if (n % 2 == 0) {
			std::cout << COLORIZE(GREEN, "even");
		} else {
			std::cout << COLORIZE(RED, "odd");
		}
		std::cout << std::endl;
	}
}

namespace Tests {
	void	repeatChar( char c, int n, std::string color ) {
		for (int i = 0; i < n; i++) {
			std::cout << color << c;
		}
		std::cout << RESET << std::endl;
	}

	void	testStringArray( void ) {
		std::string strings[] = {
			"Hello", "World", "42", "Cpp", "Module07"
		};
		iter(strings, 5, Utils::invertCase);
		iter(strings, 5, print<std::string>);
	}

	void	testIntArray( void ) {
		int ints[] = { 1, 2, 3, 4, 5 };

		iter(ints, 5, Utils::isEven);
	}
}

int		main( void ) {
	Tests::repeatChar('=', 36, BOLD_CYAN);
	std::cout << "         String Array Tests " << std::endl;
	Tests::repeatChar('=', 36, BOLD_CYAN);
	Tests::testStringArray();

	Tests::repeatChar('=', 36, BOLD_CYAN);
	std::cout << "         Integer Array Tests " << std::endl;
	Tests::repeatChar('=', 36, BOLD_CYAN);
	Tests::testIntArray();
	
	return (0);
}
