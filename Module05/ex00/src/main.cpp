#include "Defines.hpp"
#include "Bureaucrat.hpp"

namespace Tests {
	void	repeatChar( char c, int n, std::string color ) {
		for (int i = 0; i < n; i++) {
			std::cout << color << c;
		}
		std::cout << RESET << std::endl;
	}

	void	testValidBureaucrat( void ) {
		try {
			Bureaucrat b1;
			std::cout << b1 << std::endl;
		} catch (const std::exception &e) {
			std::cout << COLORIZE(RED, e.what()) << std::endl;
		}
		try {
			Bureaucrat b2("Bureaucrat2", 1);
			b2.decrementGrade();
			std::cout << b2 << std::endl;
		} catch (const std::exception &e) {
			std::cout << COLORIZE(RED, e.what()) << std::endl;
		}
		try {
			Bureaucrat b3("Bureaucrat3", 150);
			b3.incrementGrade();
			std::cout << b3 << std::endl;
		} catch (const std::exception &e) {
			std::cout << COLORIZE(RED, e.what()) << std::endl;
		}
	}

	void	testInvalidBureaucrat( void ) {
		try {
			Bureaucrat b1("Bureaucrat1", -10);
			std::cout << b1 << std::endl;
		} catch (const std::exception &e) {
			std::cout << COLORIZE(RED, e.what()) << std::endl;
		}
		try {
			Bureaucrat b2("Bureaucrat2", 1);
			b2.incrementGrade();
			std::cout << b2 << std::endl;
		} catch (const std::exception &e) {
			std::cout << COLORIZE(RED, e.what()) << std::endl;
		}
		try {
			Bureaucrat b3("Bureaucrat3", 150);
			b3.decrementGrade();
			std::cout << b3 << std::endl;
		} catch (const std::exception &e) {
			std::cout << COLORIZE(RED, e.what()) << std::endl;
		}
	}
}

int main( void ) {
	Tests::repeatChar('=', 42, CYAN);
	std::cout << "          Valid Bureaucrat Tests " << std::endl;
	Tests::repeatChar('=', 42, CYAN);
	Tests::testValidBureaucrat();

	std::cout << std::endl;
	Tests::repeatChar('=', 42, CYAN);
	std::cout << "         Invalid Bureaucrat Tests " << std::endl;
	Tests::repeatChar('=', 42, CYAN);
	Tests::testInvalidBureaucrat();

	return (0);
}
