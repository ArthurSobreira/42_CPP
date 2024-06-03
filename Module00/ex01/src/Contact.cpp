#include "Contact.hpp"

Contact::Contact() {
	std::cout << "Constructor Called" << std::endl;
	this->_firstName = "";
	this->_lastName = "";
	this->_nickname = "";
	this->_phoneNumber = "";
	this->_darkestSecret = "";
};

Contact::~Contact() {
	std::cout << "Destructor Called" << std::endl;
};

