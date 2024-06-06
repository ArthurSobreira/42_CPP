#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include "PhoneBook.hpp"
#include "Defines.hpp"

namespace PBUtils
{
	bool	parseName(std::string name, std::string nameType) {
		if (name.empty()) {
			std::cout << ERROR_EMPTY_FIELD(nameType) << std::endl;
			return (false);
		}
		for (size_t i = 0; i < name.length(); i++) {
			if (!std::isalpha(name[i])) {
				std::cout << ERROR_INVALID_NAME(nameType) << std::endl;
				return (false);
			}
		}
		return (true);
	}

	bool	parsePhoneNumber(std::string phoneNumber, std::string numberType) {
		if (phoneNumber.empty()) {
			std::cout << ERROR_EMPTY_FIELD("Phone Number") << std::endl;
			return (false);
		}
		for (size_t i = 0; i < phoneNumber.length(); i++) {
			if (!std::isdigit(phoneNumber[i])) {
				std::cout << ERROR_INVALID_NUMBER(numberType) << std::endl;
				return (false);
			}
		}
		if (phoneNumber.size() < 10 || phoneNumber.size() > 15) {
			std::cout << ERROR_NUMBER_LENGTH << std::endl;
			return (false);
		}
		return (true);
	}

	bool parseIndex(std::string index, short contactNumber, std::string numberType) {
		if (index.empty()) {
			std::cout << ERROR_EMPTY_FIELD("Index") << std::endl;
			return (false);
		}
		for (size_t i = 0; i < index.length(); i++) {
			if (!std::isdigit(index[i])) {
				std::cout << ERROR_INVALID_NUMBER(numberType) << std::endl;
				return (false);
			}
		}
		if (std::atoi(index.c_str()) < 1 || std::atoi(index.c_str()) > contactNumber) {
			std::cout << ERROR_INVALID_INDEX << std::endl;
			return (false);
		}
		return (true);
	}

	std::string truncateString(std::string str) {
		if (str.length() > 10)
			return (str.substr(0, 9) + ".");
		return (str);
	}

	void	clearCin(void) {
		std::cin.eof();
		fflush(stdin);
		std::clearerr(stdin);
		std::cin.clear();
	}
}

short	PhoneBook::_contactNumber = 0;

PhoneBook::PhoneBook() {};

PhoneBook::~PhoneBook() {};

Contact PhoneBook::createContact(void) {
	Contact		contact;
	std::string	input;

	/* First Name */
	do {
		std::cout << INPUT_FIRST_NAME;
		std::getline(std::cin, input);
	} while (!PBUtils::parseName(input, "First Name"));
	contact.setFirstName(input);
	input.clear();
	PBUtils::clearCin();

	/* Last Name */
	do {
		std::cout << INPUT_LAST_NAME;
		std::getline(std::cin, input);
	} while (!PBUtils::parseName(input, "Last Name"));
	contact.setLastName(input);
	input.clear();
	PBUtils::clearCin();

	/* Nickname */
	do {
		std::cout << INPUT_NICKNAME;
		std::getline(std::cin, input);
		if (input.empty())
			std::cout << ERROR_EMPTY_FIELD("Nickname") << std::endl;
	} while (input.empty());
	contact.setNickname(input);
	input.clear();
	PBUtils::clearCin();

	/* Phone Number */
	do {
		std::cout << INPUT_PHONE_NUMBER;
		std::getline(std::cin, input);
	} while (!PBUtils::parsePhoneNumber(input, "Phone Number"));
	contact.setPhoneNumber(input);
	input.clear();
	PBUtils::clearCin();

	/* Darkest Secret */
	do {
		std::cout << INPUT_DARKEST_SECRET;
		std::getline(std::cin, input);
		if (input.empty())
			std::cout << ERROR_EMPTY_FIELD("Darkest Secret") << std::endl;
	} while (input.empty());
	contact.setDarkestSecret(input);
	input.clear();
	PBUtils::clearCin();

	return (contact);
}

void PhoneBook::addContact(Contact contact) {
	std::string	firstName = contact.getFirstName();
	std::string	lastName = contact.getLastName();
	std::string	nickname = contact.getNickname();
	std::string	phoneNumber = contact.getPhoneNumber();
	std::string	darkestSecret = contact.getDarkestSecret();
	size_t		index = this->_contactNumber % 8;

	this->_contacts[index].setFirstName(firstName);
	this->_contacts[index].setLastName(lastName);
	this->_contacts[index].setNickname(nickname);
	this->_contacts[index].setPhoneNumber(phoneNumber);
	this->_contacts[index].setDarkestSecret(darkestSecret);
	this->_contactNumber++;
}

void PhoneBook::searchContact(void) {
	std::string	input;
	int			index;

	if (this->_contactNumber == 0) {
		std::cout << ERROR_PHONEBOOK_EMPTY << std::endl;
		return ;
	}

	std::cout << "     Index|First Name| Last Name|  Nickname" << std::endl;
	for (int i = 0; i < std::min(this->_contactNumber, static_cast<short>(8)); i++) {
		std::cout << std::setw(10) << i + 1 << "|";
		std::cout << std::setw(10) << \
		PBUtils::truncateString(this->_contacts[i].getFirstName())<< "|";
		std::cout << std::setw(10) << \
		PBUtils::truncateString(this->_contacts[i].getLastName()) << "|";
		std::cout << std::setw(10) << \
		PBUtils::truncateString(this->_contacts[i].getNickname()) << std::endl;
	}

	do {
		std::cout << INPUT_SEARCH;
		std::getline(std::cin, input);
	} while (!PBUtils::parseIndex(input, \
		std::min(this->_contactNumber, static_cast<short>(8)), "Index"));

	index = std::atoi(input.c_str());
	std::cout << PRINT_FIRST_NAME << this->_contacts[index - 1].getFirstName() << std::endl;
	std::cout << PRINT_LAST_NAME << this->_contacts[index - 1].getLastName() << std::endl;
	std::cout << PRINT_NICKNAME << this->_contacts[index - 1].getNickname() << std::endl;
	std::cout << PRINT_PHONE_NUMBER << this->_contacts[index - 1].getPhoneNumber() << std::endl;
	std::cout << PRINT_DARKEST_SECRET << this->_contacts[index - 1].getDarkestSecret() << std::endl;

	input.clear();
	PBUtils::clearCin();
}
