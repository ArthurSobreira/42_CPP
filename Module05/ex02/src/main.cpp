#include "Defines.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

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
			Bureaucrat b2("Bureaucrat1", 26);
			ppf2.beSigned(b2);
			b2.executeForm(ppf2);
			std::cout << ppf2 << std::endl;
		} catch (const std::exception &e) {
			std::cout << COLORIZE(RED, e.what()) << std::endl;
		}
		try {
			PresidentialPardonForm ppf3("Target1");
			Bureaucrat b3("Bureaucrat1", 5);
			b3.executeForm(ppf3);
			std::cout << ppf3 << std::endl;
		} catch (const std::exception &e) {
			std::cout << COLORIZE(RED, e.what()) << std::endl;
		}
	}

	void	testValidRobotomyRequestForm( void ) {
		try {
			RobotomyRequestForm rrf1;
			std::cout << rrf1 << std::endl;
		} catch (const std::exception &e) {
			std::cout << COLORIZE(RED, e.what()) << std::endl;
		}
		try {
			RobotomyRequestForm rrf2("Target1");
			std::cout << rrf2 << std::endl;
		} catch (const std::exception &e) {
			std::cout << COLORIZE(RED, e.what()) << std::endl;
		}
		try {
			RobotomyRequestForm rrf3("Target2");
			Bureaucrat b1("Bureaucrat1", 5);
			rrf3.beSigned(b1);
			b1.executeForm(rrf3);
			std::cout << rrf3 << std::endl;
		} catch (const std::exception &e) {
			std::cout << COLORIZE(RED, e.what()) << std::endl;
		}
	}

	void	testInvalidRobotomyRequestForm( void ) {
		try {
			RobotomyRequestForm rrf1("Target1");
			Bureaucrat b1("Bureaucrat1", 50);
			rrf1.beSigned(b1);
			b1.executeForm(rrf1);
			std::cout << rrf1 << std::endl;
		} catch (const std::exception &e) {
			std::cout << COLORIZE(RED, e.what()) << std::endl;
		}
		try {
			RobotomyRequestForm rrf2("Target1");
			Bureaucrat b2("Bureaucrat1", 75);
			rrf2.beSigned(b2);
			b2.executeForm(rrf2);
			std::cout << rrf2 << std::endl;
		} catch (const std::exception &e) {
			std::cout << COLORIZE(RED, e.what()) << std::endl;
		}
		try {
			RobotomyRequestForm rrf3("Target1");
			Bureaucrat b3("Bureaucrat1", 40);
			b3.executeForm(rrf3);
			std::cout << rrf3 << std::endl;
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
	std::cout << "     Invalid Presidential Pardon Form " << std::endl;
	Tests::repeatChar('=', 42, CYAN);
	Tests::testInvalidPresidentialPardonForm();

	std::cout << std::endl;
	Tests::repeatChar('=', 42, CYAN);
	std::cout << "        Valid Robotomy Request Form " << std::endl;
	Tests::repeatChar('=', 42, CYAN);
	Tests::testValidRobotomyRequestForm();

	std::cout << std::endl;
	Tests::repeatChar('=', 42, CYAN);
	std::cout << "       Invalid Robotomy Request Form " << std::endl;
	Tests::repeatChar('=', 42, CYAN);
	Tests::testInvalidRobotomyRequestForm();

	return (0);
}
