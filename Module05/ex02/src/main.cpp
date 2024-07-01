#include "Defines.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

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
			Bureaucrat b1("Bureaucrat1", 45);
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

	void	testValidShrubberyCreationForm( void ) {
		try {
			ShrubberyCreationForm scf1;
			std::cout << scf1 << std::endl;
		} catch (const std::exception &e) {
			std::cout << COLORIZE(RED, e.what()) << std::endl;
		}
		try {
			ShrubberyCreationForm scf2("Target1");
			std::cout << scf2 << std::endl;
		} catch (const std::exception &e) {
			std::cout << COLORIZE(RED, e.what()) << std::endl;
		}
		try {
			ShrubberyCreationForm scf3("Target2");
			Bureaucrat b1("Bureaucrat1", 137);
			scf3.beSigned(b1);
			b1.executeForm(scf3);
			std::cout << scf3 << std::endl;
		} catch (const std::exception &e) {
			std::cout << COLORIZE(RED, e.what()) << std::endl;
		}
	}

	void	testInvalidShrubberyCreationForm( void ) {
		try {
			ShrubberyCreationForm scf1("Target1");
			Bureaucrat b1("Bureaucrat1", 140);
			scf1.beSigned(b1);
			b1.executeForm(scf1);
			std::cout << scf1 << std::endl;
		} catch (const std::exception &e) {
			std::cout << COLORIZE(RED, e.what()) << std::endl;
		}
		try {
			ShrubberyCreationForm scf2("Target1");
			Bureaucrat b2("Bureaucrat1", 150);
			scf2.beSigned(b2);
			b2.executeForm(scf2);
			std::cout << scf2 << std::endl;
		} catch (const std::exception &e) {
			std::cout << COLORIZE(RED, e.what()) << std::endl;
		}
		try {
			ShrubberyCreationForm scf3("Target1");
			Bureaucrat b3("Bureaucrat1", 130);
			b3.executeForm(scf3);
			std::cout << scf3 << std::endl;
		} catch (const std::exception &e) {
			std::cout << COLORIZE(RED, e.what()) << std::endl;
		}
	}
}

int main( void ) {
	Tests::repeatChar('=', 43, CYAN);
	std::cout << "      Valid Presidential Pardon Form " << std::endl;
	Tests::repeatChar('=', 43, CYAN);
	Tests::testValidPresidentialPardonForm();

	std::cout << std::endl;
	Tests::repeatChar('=', 43, CYAN);
	std::cout << "     Invalid Presidential Pardon Form " << std::endl;
	Tests::repeatChar('=', 43, CYAN);
	Tests::testInvalidPresidentialPardonForm();

	std::cout << std::endl;
	Tests::repeatChar('=', 43, CYAN);
	std::cout << "        Valid Robotomy Request Form " << std::endl;
	Tests::repeatChar('=', 43, CYAN);
	Tests::testValidRobotomyRequestForm();

	std::cout << std::endl;
	Tests::repeatChar('=', 43, CYAN);
	std::cout << "       Invalid Robotomy Request Form " << std::endl;
	Tests::repeatChar('=', 43, CYAN);
	Tests::testInvalidRobotomyRequestForm();

	std::cout << std::endl;
	Tests::repeatChar('=', 43, CYAN);
	std::cout << "       Valid Shrubbery Creation Form " << std::endl;
	Tests::repeatChar('=', 43, CYAN);
	Tests::testValidShrubberyCreationForm();

	std::cout << std::endl;
	Tests::repeatChar('=', 43, CYAN);
	std::cout << "      Invalid Shrubbery Creation Form " << std::endl;
	Tests::repeatChar('=', 43, CYAN);
	Tests::testInvalidShrubberyCreationForm();

	return (0);
}
