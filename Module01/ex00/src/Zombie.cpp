#include "Zombie.hpp"
#include "Defines.hpp"

Zombie::Zombie( void ) {
	std::cout << CYAN << "Zombie constructor called" \
		<< RESET << std::endl;
}

Zombie::~Zombie( void ) {
	std::cout << RED << "Zombie" << this->getName() << " destroyed" \
		<< RESET << std::endl;
}

/* Getter and Setter _name */
std::string Zombie::getName( void ) const {
	return (this->_name);
}

void Zombie::setName( std::string name ) {
	this->_name = name;
}

void Zombie::announce( void ) {
	std::cout << GREEN << this->getName() << ": BraiiiiiiinnnzzzZ..." \
		<< RESET << std::endl;
}
