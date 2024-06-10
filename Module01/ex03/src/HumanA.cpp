#include "HumanA.hpp"
#include "Defines.hpp"

HumanA::HumanA( std::string name, Weapon& weapon ) : _name(name), _weapon(weapon) {};

HumanA::~HumanA( void ) {};

void	HumanA::attack( void ) {
	std::cout << MAGENTA << this->_name << RESET << " attacks with their " << 
	BLUE << this->_weapon.getType() << RESET << std::endl;
}
