#include "Contact.hpp"

Contact::Contact() {
	this->_firstName = "";
	this->_lastName = "";
	this->_nickname = "";
	this->_phoneNumber = "";
	this->_darkestSecret = "";
};

Contact::~Contact() {};

/* Getter and Setter _firstName */
std::string	Contact::getFirstName(void) const {
	return (this->_firstName);
}

void Contact::setFirstName(std::string firstName) {
	this->_firstName = firstName;
}

/* Getter and Setter _lastName */
std::string Contact::getLastName(void) const {
	return (this->_lastName);
}

void Contact::setLastName(std::string lastName) {
	this->_lastName = lastName;
}

/* Getter and Setter _nickname */
std::string Contact::getNickname(void) const {
	return (this->_nickname);
}

void Contact::setNickname(std::string nickname) {
	this->_nickname = nickname;
}

/* Getter and Setter _phoneNumber */
std::string Contact::getPhoneNumber(void) const {
	return (this->_phoneNumber);
}

void Contact::setPhoneNumber(std::string phoneNumber) {
	this->_phoneNumber = phoneNumber;
}

/* Getter and Setter _darkestSecret */
std::string Contact::getDarkestSecret(void) const {
	return (this->_darkestSecret);
}

void Contact::setDarkestSecret(std::string darkestSecret) {
	this->_darkestSecret = darkestSecret;
}
