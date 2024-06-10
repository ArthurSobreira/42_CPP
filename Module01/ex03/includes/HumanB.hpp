#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanB {
	private:
		std::string	_name;
		Weapon		*_weapon;

	public:
		/* Constructor Method */
		HumanB( std::string name );

		/* Destructor Method */
		~HumanB( void );

		/* Public Methods */
		void	attack( void );
		void	setWeapon( Weapon& weapon );
};

#endif