#include "Defines.hpp"
#include "AAnimal.hpp"

/* Constructor Method */
AAnimal::AAnimal( void ) : _type("Animal") {
	std::cout << "AAnimal Default Constructor called" << std::endl;
}

/* Copy Constructor Method */
AAnimal::AAnimal( const AAnimal &other ) {
	std::cout << "AAnimal Copy Constructor called" << std::endl;
	*this = other;
}

/* Copy Assignment Operator Overload */
AAnimal &AAnimal::operator=( const AAnimal &other ) {
	std::cout << "AAnimal Copy Assignment Operator called" << std::endl;
	if (this != &other) {
		this->_type = other.getType();
	}
	return (*this);
}

/* Destructor Method */
AAnimal::~AAnimal( void ) {
	std::cout << "AAnimal Destructor called" << std::endl;
}

/* Getter and Setter _type */
std::string AAnimal::getType( void ) const {
	return (this->_type);
}

void	AAnimal::setType( std::string type ) {
	this->_type = type;
}

/* Public Method */
void	AAnimal::makeSound( void ) const {
	std::cout << ANIMAL_SOUND_MESSAGE(this->getType()) << std::endl;
}
