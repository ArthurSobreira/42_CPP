#include "Defines.hpp"
#include "easyfind.hpp"
#include <vector>
#include <deque>

namespace Utils {
	template <typename T> void	fillContainer( T &container, int n ) {
		for (int i = 0; i < n; i++) {
			container.push_back(i);
		}
	}

	template <typename T> void	printContainer( T &container ) {
		typename T::iterator it = container.begin();

		while (it != container.end()) {
			std::cout << "[" << *it << "]";
			it++;
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

	void	testVectorContainer( void ) {
		std::vector<int> vec;
		std::vector<int>::iterator occ;

		Utils::fillContainer(vec, 7);
		Utils::printContainer(vec);

		try {
			occ = easyfind(vec, 3);
			std::cout << COLORIZE(YELLOW, "Value Found: ") << 
			*occ << std::endl;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}

		try {
			occ = easyfind(vec, 42);
			std::cout << COLORIZE(YELLOW, "Value Found: ") <<
			*occ << std::endl;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}

	void	testDequeContainer( void ) {
		std::deque<int>	deq;
		std::deque<int>::iterator occ;

		Utils::fillContainer(deq, 10);
		Utils::printContainer(deq);

		try {
			occ = easyfind(deq, 8);
			std::cout << COLORIZE(YELLOW, "Value Found: ") << 
			*occ << std::endl;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}

		try {
			occ = easyfind(deq, -10);
			std::cout << COLORIZE(YELLOW, "Value Found: ") <<
			*occ << std::endl;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
}

int main( void ){
	Tests::repeatChar('=', 36, BOLD_CYAN);
	std::cout << "       Vector Container Tests " << std::endl;
	Tests::repeatChar('=', 36, BOLD_CYAN);
	Tests::testVectorContainer();

	Tests::repeatChar( '=', 36, BOLD_CYAN );
	std::cout << "        Deque Container Tests " << std::endl;
	Tests::repeatChar( '=', 36, BOLD_CYAN );
	Tests::testDequeContainer();

	return (0);
}
