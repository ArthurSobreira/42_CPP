#include "Defines.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"

namespace Tests {
	void	repeatChar( char c, int n, std::string color ) {
		for (int i = 0; i < n; i++) {
			std::cout << color << c;
		}
		std::cout << RESET << std::endl;
	}

	void	testValidIntern( void ) {
		try {
			Intern intern1;
			AForm *form1 = intern1.makeForm("Presidential Pardon", "Target1");
			std::cout << *form1 << std::endl;
			delete form1;
		} catch (const std::exception &e) {
			std::cout << COLORIZE(RED, e.what()) << std::endl;
		}
		try {
			Bureaucrat bureaucrat1("Bureaucrat", 50);	
			Intern intern2;
			AForm *form2 = intern2.makeForm("Robotomy Request", "Target2");
			form2->beSigned(bureaucrat1);
			std::cout << *form2 << std::endl;
			delete form2;
		} catch (const std::exception &e) {
			std::cout << COLORIZE(RED, e.what()) << std::endl;
		}
		try {
			Bureaucrat bureaucrat2("Bureaucrat", 137);
			Intern intern3;
			AForm *form3 = intern3.makeForm("Shrubbery Creation", "Target3");
			form3->beSigned(bureaucrat2);
			bureaucrat2.executeForm(*form3);
			std::cout << *form3 << std::endl;
			delete form3;
		} catch (const std::exception &e) {
			std::cout << COLORIZE(RED, e.what()) << std::endl;
		}
	}

	void	testInvalidIntern( void ) {
		try {
			Intern intern1;
			AForm *form1 = intern1.makeForm("Invalid Form", "Target2");
			std::cout << *form1 << std::endl;
			delete form1;
		} catch (const std::exception &e) {
			std::cout << COLORIZE(RED, e.what()) << std::endl;
		}
		try {
			Bureaucrat bureaucrat1("Bureaucrat", 1);
			Intern intern2;
			AForm *form2 = intern2.makeForm("Invalid Form", "Target2");
			std::cout << *form2 << std::endl;
			form2->beSigned(bureaucrat1);
			bureaucrat1.executeForm(*form2);
			delete form2;
		} catch (const std::exception &e) {
			std::cout << COLORIZE(RED, e.what()) << std::endl;
		}
	}
}

int main( void ) {
	Tests::repeatChar('=', 41, CYAN);
	std::cout << "            Valid Intern Test " << std::endl;
	Tests::repeatChar('=', 41, CYAN);
	Tests::testValidIntern();

	std::cout << std::endl;
	Tests::repeatChar('=', 41, CYAN);
	std::cout << "           Invalid Intern Test " << std::endl;
	Tests::repeatChar('=', 41, CYAN);
	Tests::testInvalidIntern();

	return (0);
}
