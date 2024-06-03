#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class Contact {
	private:
		std::string _firstName;
		std::string	_lastName;
		std::string	_nickname;
		std::string	_phoneNumber;
		std::string	_darkestSecret;

	public:
		/* Constructor Method */
		Contact();

		/* Destructor Method */
		~Contact();

		/* Getter and Setter _firstName */
		std::string	getFirstName(void) const;
		void		setFirstName(std::string firstName);

		/* Getter and Setter _lastName */
		std::string	getLastName(void) const;
		void		setLastName(std::string lastName);

		/* Getter and Setter _nickname */
		std::string	getNickname(void) const;
		void		setNickname(std::string nickname);

		/* Getter and Setter _phoneNumber */
		std::string	getPhoneNumber(void) const;
		void		setPhoneNumber(std::string phoneNumber);

		/* Getter and Setter _darkestSecret */
		std::string	getDarkestSecret(void) const;
		void		setDarkestSecret(std::string darkestSecret);
};

#endif