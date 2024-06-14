#include "Character.hpp"
#include "ICharacter.hpp"
#include "AMateria.hpp"

/* Constructor Method */
Character::Character( void ) : _name("default"), _inventory() {
	std::cout << "Character Default Constructor called" << std::endl;
}

Character::Character( std::string const &name ) : _name(name), _inventory() {
	std::cout << "Character Name Constructor called" << std::endl;
}

/* Copy Constructor Method */
Character::Character( const Character &other ) : _name(other.getName()), _inventory() {
	std::cout << "Character Copy Constructor called" << std::endl;
	*this = other;
}

/* Copy Assignment Operator Overload */
Character &Character::operator=( const Character &other ) {
	std::cout << "Character Copy Assignment Operator called" << std::endl;
	if (this != &other) {
		this->_name = other.getName();
		for (int i = 0; i < 4; i++) {
			if (other._inventory[i]) {
				this->_inventory[i] = other._inventory[i]->clone();
			} else {
				this->_inventory[i] = NULL;
			}
		}
	}
	return (*this);
}

/* Destructor Method */
Character::~Character( void ) {
	std::cout << "Character Destructor called" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (this->_inventory[i]) {
			delete this->_inventory[i];
		}
	}
}

/* Getter _name Method */
std::string const &Character::getName( void ) const {
	return (this->_name);
}

/* Public Method */
void	Character::equip( AMateria *m ) {
	for (int i = 0; i < 4; i++) {
		if (!this->_inventory[i]) {
			this->_inventory[i] = m;
			if (m) {
				std::cout << "AMateria " << m->getType() \
				<< " equipped" << std::endl;
			}
			return ;
		}
	}
	std::cout << "Inventory is full" << std::endl;
	if (m) {
		delete m;
	}
}

void	Character::unequip( int idx ) {
	if (idx >= 0 && idx < 4 && this->_inventory[idx]) {
		std::cout << "AMateria " << this->_inventory[idx]->getType() \
		<< " unequipped" << std::endl;
		this->_inventory[idx] = NULL;
	} else {
		std::cout << "Invalid index" << std::endl;
	}
}

void Character::use( int idx, ICharacter &target ) {
	if (idx >= 0 && idx < 4 && this->_inventory[idx]) {
		this->_inventory[idx]->use(target);
	} else {
		std::cout << "Invalid index" << std::endl;
	}
}
