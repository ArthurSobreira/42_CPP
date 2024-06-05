#include <iostream>
#include <string>
#include <cstdio>
#include "PhoneBook.hpp"
#include "Defines.hpp"
#include "Contact.hpp"

namespace Utils {
	std::string	stringStrip(std::string str) {
		size_t	start = str.find_first_not_of(" \t");
		size_t	end = str.find_last_not_of(" \t");

		if (start == std::string::npos)
			return ("");
		return (str.substr(start, end - start + 1));
	}

	void	stringToUpper(std::string &str) {
		for (size_t i = 0; i < str.length(); i++) {
			str[i] = toupper(str[i]);
		}
	}

	void	repeatChar(char c, int n, std::string color) {
		for (int i = 0; i < n; i++) {
			std::cout << color << c;
		}
		std::cout << RESET << std::endl;
	}

	void	clearCin(void) {
		fflush(NULL);
		std::clearerr(stdin);
		std::cin.clear();
	}
}

int	main(void) {
	Contact	contact;
	std::string	command;

	Utils::repeatChar('=', HEADER_SIZE, BOLD_GREEN);
	std::cout << WELCOME_MESSAGE << std::endl;
	Utils::repeatChar('=', HEADER_SIZE, BOLD_GREEN);

	do {
		std::cout << INPUT_MESSAGE;
		std::getline(std::cin, command);
		Utils::stringToUpper(command);
		command = Utils::stringStrip(command);
		if (command == "HELP")
			std::cout << HELP_MESSAGE << std::endl;
	} while (command != "EXIT");
	return (0);
}
