#include "Defines.hpp"
#include "Bureaucrat.hpp"
#include "Form.hpp"

namespace Tests {
	void	repeatChar( char c, int n, std::string color ) {
		for (int i = 0; i < n; i++) {
			std::cout << color << c;
		}
		std::cout << RESET << std::endl;
	}

	void	testValidForm( void ) {
		try {
			Form f1;
			std::cout << f1 << std::endl;
		} catch (const std::exception &e) {
			std::cout << COLORIZE(RED, e.what()) << std::endl;
		}
		try {
			Form f2("Form1", 1, 1);
			std::cout << f2 << std::endl;
		} catch (const std::exception &e) {
			std::cout << COLORIZE(RED, e.what()) << std::endl;
		}
		try {
			Form f3("Form2", 150, 150);
			std::cout << f3 << std::endl;
		} catch (const std::exception &e) {
			std::cout << COLORIZE(RED, e.what()) << std::endl;
		}
	}

	void	testInvalidForm( void ) {
		try {
			Form f1("Form1", 0, 1);
			std::cout << f1 << std::endl;
		} catch (const std::exception &e) {
			std::cout << COLORIZE(RED, e.what()) << std::endl;
		}
		try {
			Form f2("Form2", 151, 152);
			std::cout << f2 << std::endl;
		} catch (const std::exception &e) {
			std::cout << COLORIZE(RED, e.what()) << std::endl;
		}
	}

	void	testValidSignForm( void ) {
		try {
			Bureaucrat b1("Bureaucrat1", 5);
			Form f1("Form1", 5, 10);
			b1.signForm(f1);
			std::cout << f1 << std::endl;
		} catch (const std::exception &e) {
			std::cout << COLORIZE(RED, e.what()) << std::endl;
		}
		try {
			Bureaucrat b2("Bureaucrat2", 120);
			Form f2("Form2", 150, 150);
			b2.signForm(f2);
			std::cout << f2 << std::endl;
		} catch (const std::exception &e) {
			std::cout << COLORIZE(RED, e.what()) << std::endl;
		}
	}

	void	testInvalidSignForm( void ) {
		try {
			Bureaucrat b1("Bureaucrat1", 10);
			Form f1("Form1", 10, 10);
			b1.decrementGrade();
			b1.signForm(f1);
			std::cout << f1 << std::endl;
		} catch (const std::exception &e) {
			std::cout << COLORIZE(RED, e.what()) << std::endl;
		}
		try {
			Bureaucrat b2("Bureaucrat2", 120);
			Form f2("Form2", 100, 100);
			b2.signForm(f2);
			std::cout << f2 << std::endl;
		} catch (const std::exception &e) {
			std::cout << COLORIZE(RED, e.what()) << std::endl;
		}
	}
}

int main( void ) {
	Tests::repeatChar('=', 44, CYAN);
	std::cout << "              Valid Form Tests " << std::endl;
	Tests::repeatChar('=', 44, CYAN);
	Tests::testValidForm();

	std::cout << std::endl;
	Tests::repeatChar('=', 44, CYAN);
	std::cout << "             Invalid Form Tests " << std::endl;
	Tests::repeatChar('=', 44, CYAN);
	Tests::testInvalidForm();

	std::cout << std::endl;
	Tests::repeatChar('=', 44, CYAN);
	std::cout << "            Valid Sign Form Tests " << std::endl;
	Tests::repeatChar('=', 44, CYAN);
	Tests::testValidSignForm();

	std::cout << std::endl;
	Tests::repeatChar('=', 44, CYAN);
	std::cout << "           Invalid Sign Form Tests " << std::endl;
	Tests::repeatChar('=', 44, CYAN);
	Tests::testInvalidSignForm();

	return (0);
}
