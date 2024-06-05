#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
	private:
		Contact	_contacts[8];
		static short	_contactNumber;

	public:
		/* Constructor Method */
		PhoneBook();

		/* Destructor Method */
		~PhoneBook();

		/* Public Methods */
		Contact	createContact(void);
		void	addContact(Contact contact);
		void	searchContact(void);
};

#endif