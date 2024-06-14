#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

/* Constructor Method */
AMateria::AMateria( void ) : _type("default") {
	std::cout << "AMateria Default Constructor called" << std::endl;
}

AMateria::AMateria( std::string const & type ) : _type(type) {
	std::cout << "AMateria Type Constructor called" << std::endl;
}

/* Copy Constructor Method */
AMateria::AMateria( const AMateria &other ) {
	std::cout << "AMateria Copy Constructor called" << std::endl;
	*this = other;
}

/* Copy Assignment Operator Overload */
AMateria &AMateria::operator=( const AMateria &other ) {
	std::cout << "AMateria Copy Assignment Operator called" << std::endl;
	if (this != &other) {
		this->_type = other.getType();
	}
	return (*this);
}

/* Destructor Method */
AMateria::~AMateria( void ) {
	std::cout << "AMateria Destructor called" << std::endl;
}

/* Getter _type Method */
std::string const &AMateria::getType( void ) const {
	return (this->_type);
}

/* Public Method */
void AMateria::use( ICharacter & target ) {
	std::cout << "AMateria Used in Targed " target.getName() << std::endl;
}
