#include "Defines.hpp"
#include "Span.hpp"
#include <cstdlib>
#include <ctime>

namespace Utils {
	void	fillVector( std::vector<int> &vec, int n, int range) {
		std::srand(std::time(NULL));
		for (int i = 0; i < n; i++) {
			vec.push_back(std::rand() % range);
		}
	}

	void	printVector( std::vector<int> &vec, bool sorted ) {
		std::vector<int>::iterator it = vec.begin();
		
		while (it != vec.end()) {
			std::cout << "[" << *it << "]";
			it++;
		}
		if (sorted) {
			std::cout << COLORIZE(GREEN, " <- Sorted Vector");
		} else {
			std::cout << COLORIZE(GREEN, " <- Unsorted Vector");
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

	void	testSubject( void ) {
		Span sp = Span(5);

		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << COLORIZE(YELLOW, "Shortest Span: ") << 
		sp.shortestSpan() << std::endl;
		std::cout << COLORIZE(YELLOW, "Longest Span:  ") <<
		sp.longestSpan() << std::endl;
	}
	
	void	testValidSpan( void ) {
		Span sp = Span(7);
		std::vector<int> vec;

		Utils::fillVector(vec, 7, 20);
		sp.populate(vec.begin(), vec.end());
		Utils::printVector(vec, false);

		std::sort(vec.begin(), vec.end());
		Utils::printVector(vec, true);

		std::cout << COLORIZE(YELLOW, "Shortest Span: ") << 
		sp.shortestSpan() << std::endl;
		std::cout << COLORIZE(YELLOW, "Longest Span:  ") <<
		sp.longestSpan() << std::endl;
	}

	void	testValidSpanHard( void ) {
		Span sp = Span(10000);
		std::vector<int> vec;

		Utils::fillVector(vec, 10000, 100000);
		sp.populate(vec.begin(), vec.end());
		Utils::printVector(vec, false);

		std::sort(vec.begin(), vec.end());
		Utils::printVector(vec, true);

		std::cout << COLORIZE(YELLOW, "Shortest Span: ") << 
		sp.shortestSpan() << std::endl;
		std::cout << COLORIZE(YELLOW, "Longest Span:  ") <<
		sp.longestSpan() << std::endl;
	
	}

	void	testInvalidSpan( void ) {
		try {
			Span sp;
			sp.addNumber(-42);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}

		try {
			Span sp = Span(2);
			sp.shortestSpan();
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}

		try {
			Span sp = Span(5);
			sp.addNumber(42);
			sp.longestSpan();
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
}

int main( void ){
	Tests::repeatChar('=', 39, BOLD_CYAN);
	std::cout << "             Subject Tests " << std::endl;
	Tests::repeatChar('=', 39, BOLD_CYAN);
	Tests::testSubject();

	Tests::repeatChar('=', 39, BOLD_CYAN);
	std::cout << "            Valid Span Tests " << std::endl;
	Tests::repeatChar('=', 39, BOLD_CYAN);
	Tests::testValidSpan();

	Tests::repeatChar('=', 39, BOLD_CYAN);
	std::cout << "         Valid Span Hard Tests " << std::endl;
	Tests::repeatChar('=', 39, BOLD_CYAN);
	Tests::testValidSpanHard();

	Tests::repeatChar('=', 39, BOLD_CYAN);
	std::cout << "           Invalid Span Tests " << std::endl;
	Tests::repeatChar('=', 39, BOLD_CYAN);
	Tests::testInvalidSpan();

	return (0);
}
