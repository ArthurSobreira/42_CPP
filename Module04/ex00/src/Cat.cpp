#include "Defines.hpp"
#include "Cat.hpp"

/* Constructor Method */
Cat::Cat( void ) : Animal() {
	std::cout << "Cat Default Constructor called" << std::endl;
	this->setType("Cat");
}

/* Copy Constructor Method */
Cat::Cat( const Cat &other ) : Animal(other) {
	std::cout << "Cat Copy Constructor called" << std::endl;
	*this = other;
}

/* Copy Assignment Operator Overload */
Cat &Cat::operator=( const Cat &other ) {
	std::cout << "Cat Copy Assignment Operator called" << std::endl;
	if (this != &other) {
		this->_type = other.getType();
	}
	return (*this);
}

/* Destructor Method */
Cat::~Cat( void ) {
	std::cout << "Cat Destructor called" << std::endl;
}

/* Public Method */
void	Cat::makeSound( void ) const {
	std::cout << CAT_SOUND_MESSAGE(this->getType()) << std::endl;
}
