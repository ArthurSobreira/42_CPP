#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanA {
	private:
		std::string	_name;
		Weapon		&_weapon;

	public:
		/* Constructor Method */
		HumanA( std::string name, Weapon& weapon );

		/* Destructor Method */
		~HumanA( void );

		/* Public Methods */
		void	attack( void );
};

#endif