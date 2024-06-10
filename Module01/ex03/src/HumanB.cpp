#include "HumanB.hpp"
#include "Defines.hpp"

HumanB::HumanB( std::string name ) : _name(name) {
	this->_weapon = NULL;
};

HumanB::~HumanB( void ) {};

void	HumanB::setWeapon( Weapon& weapon ) {
	this->_weapon = &weapon;
}

void	HumanB::attack( void ) {
	if (this->_weapon == NULL) {
		std::cout << MAGENTA << this->_name << RESET << " has no weapon to attack with" << std::endl;
	}
	else {
		std::cout << MAGENTA << this->_name << RESET << " attacks with their " << 
		BLUE << this->_weapon->getType() << RESET << std::endl;
	}
}
