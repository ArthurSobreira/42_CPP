#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
	private:
		Contact	_contacts[8];
		static int	_contactIndex;

	public:
		/* Constructor Method */
		PhoneBook();

		/* Destructor Method */
		~PhoneBook();

		
};

#endif