#include "Defines.hpp"
#include "Dog.hpp"

/* Constructor Method */
Dog::Dog( void ) : Animal() {
	std::cout << "Dog Default Constructor called" << std::endl;
	this->setType("Dog");
	this->_brain = new Brain();
}

/* Copy Constructor Method */
Dog::Dog( const Dog &other ) : Animal(other) {
	std::cout << "Dog Copy Constructor called" << std::endl;
	this->_brain = new Brain();
	*this = other;
}

/* Copy Assignment Operator Overload */
Dog &Dog::operator=( const Dog &other ) {
	std::cout << "Dog Copy Assignment Operator called" << std::endl;
	if (this != &other) {
		this->_type = other.getType();
		*this->_brain = *other._brain;
	}
	return (*this);
}

/* Destructor Method */
Dog::~Dog( void ) {
	std::cout << "Dog Destructor called" << std::endl;
	delete this->_brain;
}

/* Public Method */
void	Dog::makeSound( void ) const {
	std::cout << DOG_SOUND_MESSAGE(this->getType()) << std::endl;
}

Brain *Dog::getBrain( void ) const {
	return (this->_brain);
}	
