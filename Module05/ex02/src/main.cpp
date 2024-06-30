#include "Defines.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"

namespace Tests {
	void	repeatChar( char c, int n, std::string color ) {
		for (int i = 0; i < n; i++) {
			std::cout << color << c;
		}
		std::cout << RESET << std::endl;
	}

	void	testValidPresidentialPardonForm( void ) {
		try {
			PresidentialPardonForm ppf1;
			std::cout << ppf1 << std::endl;
		} catch (const std::exception &e) {
			std::cout << COLORIZE(RED, e.what()) << std::endl;
		}
		try {
			PresidentialPardonForm ppf2("Target1");
			std::cout << ppf2 << std::endl;
		} catch (const std::exception &e) {
			std::cout << COLORIZE(RED, e.what()) << std::endl;
		}
		try {
			PresidentialPardonForm ppf3("Target2");
			Bureaucrat b1("Bureaucrat1", 5);
			ppf3.beSigned(b1);
			b1.executeForm(ppf3);
			std::cout << ppf3 << std::endl;
		} catch (const std::exception &e) {
			std::cout << COLORIZE(RED, e.what()) << std::endl;
		}
	}

	void	testInvalidPresidentialPardonForm( void ) {
		try {
			PresidentialPardonForm ppf1("Target1");
			Bureaucrat b1("Bureaucrat1", 10);
			ppf1.beSigned(b1);
			b1.executeForm(ppf1);
			std::cout << ppf1 << std::endl;
		} catch (const std::exception &e) {
			std::cout << COLORIZE(RED, e.what()) << std::endl;
		}

		try {
			PresidentialPardonForm ppf2("Target1");
			Bureaucrat b1("Bureaucrat1", 26);
			ppf2.beSigned(b1);
			b1.executeForm(ppf2);
			std::cout << ppf2 << std::endl;
		} catch (const std::exception &e) {
			std::cout << COLORIZE(RED, e.what()) << std::endl;
		}

		try {
			PresidentialPardonForm ppf3("Target1");
			Bureaucrat b1("Bureaucrat1", 5);
			b1.executeForm(ppf3);
			std::cout << ppf3 << std::endl;
		} catch (const std::exception &e) {
			std::cout << COLORIZE(RED, e.what()) << std::endl;
		}
	}
}

int main( void ) {
	Tests::repeatChar('=', 42, CYAN);
	std::cout << "      Valid Presidential Pardon Form " << std::endl;
	Tests::repeatChar('=', 42, CYAN);
	Tests::testValidPresidentialPardonForm();

	std::cout << std::endl;
	Tests::repeatChar('=', 42, CYAN);
	std::cout << "    Invalid Presidential Pardon Form " << std::endl;
	Tests::repeatChar('=', 42, CYAN);
	Tests::testInvalidPresidentialPardonForm();

	return (0);
}
