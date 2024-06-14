#include "ICharacter.hpp"
#include "Ice.hpp"

/* Constructor Method */
Ice::Ice( void ) : AMateria("ice") {
	std::cout << "Ice Default Constructor called" << std::endl;
}

/* Copy Constructor Method */
Ice::Ice( const Ice &other ) : AMateria(other) {
	std::cout << "Ice Copy Constructor called" << std::endl;
	*this = other;
}

/* Copy Assignment Operator Overload */
Ice &Ice::operator=( const Ice &other ) {
	std::cout << "Ice Copy Assignment Operator called" << std::endl;
	(void)&other
	this->_type = "ice";
	return (*this);
}

/* Destructor Method */
Ice::~Ice( void ) {
	std::cout << "Ice Destructor called" << std::endl;
}

/* Public Method */
AMateria *Ice::clone( void ) const {
	std::cout << "Ice Clone called" << std::endl;
	return (new Ice(*this));
}

void Ice::use( ICharacter & target ) {
	std::cout << "* shoots an ice bolt at " << target.getName() \
	<< " *" << std::endl;
}
