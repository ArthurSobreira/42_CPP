#include "Cure.hpp"

/* Constructor Method */
Cure::Cure( void ) : AMateria("cure") {
	std::cout << "Cure Default Constructor called" << std::endl;
}

/* Copy Constructor Method */
Cure::Cure( const Cure &other ) : AMateria(other) {
	std::cout << "Cure Copy Constructor called" << std::endl;
	*this = other;
}

/* Copy Assignment Operator Overload */
Cure &Cure::operator=( const Cure &other ) {
	std::cout << "Cure Copy Assignment Operator called" << std::endl;
	if (this != &other) {
		this->_type = other.getType();
	}
	return (*this);
}

/* Destructor Method */
Cure::~Cure( void ) {
	std::cout << "Cure Destructor called" << std::endl;
}

/* Public Method */
AMateria *Cure::clone( void ) const {
	std::cout << "Cure Clone called" << std::endl;
	return (new Cure(*this));
}

void Cure::use( ICharacter & target ) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
