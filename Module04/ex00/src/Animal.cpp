#include "Defines.hpp"
#include "Animal.hpp"

/* Constructor Method */
Animal::Animal( void ) : _type("Animal") {
	std::cout << "Animal Default Constructor called" << std::endl;
}

/* Copy Constructor Method */
Animal::Animal( const Animal &other ) {
	std::cout << "Animal Copy Constructor called" << std::endl;
	*this = other;
}

/* Copy Assignment Operator Overload */
Animal &Animal::operator=( const Animal &other ) {
	std::cout << "Animal Copy Assignment Operator called" << std::endl;
	if (this != &other) {
		this->_type = other.getType();
	}
	return (*this);
}

/* Destructor Method */
Animal::~Animal( void ) {
	std::cout << "Animal Destructor called" << std::endl;
}

/* Getter and Setter _type */
std::string Animal::getType( void ) const {
	return (this->_type);
}

void	Animal::setType( std::string type ) {
	this->_type = type;
}

/* Public Method */
void	Animal::makeSound( void ) const {
	std::cout << ANIMAL_SOUND_MESSAGE(this->getType()) << std::endl;
}
