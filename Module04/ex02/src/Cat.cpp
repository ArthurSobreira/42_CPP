#include "Defines.hpp"
#include "Cat.hpp"

/* Constructor Method */
Cat::Cat( void ) : AAnimal() {
	std::cout << "Cat Default Constructor called" << std::endl;
	this->setType("Cat");
	this->_brain = new Brain();
}

/* Copy Constructor Method */
Cat::Cat( const Cat &other ) : AAnimal(other) {
	std::cout << "Cat Copy Constructor called" << std::endl;
	this->_brain = new Brain();
	*this = other;
}

/* Copy Assignment Operator Overload */
Cat &Cat::operator=( const Cat &other ) {
	std::cout << "Cat Copy Assignment Operator called" << std::endl;
	if (this != &other) {
		this->_type = other.getType();
		*this->_brain = *other._brain;
	}
	return (*this);
}

/* Destructor Method */
Cat::~Cat( void ) {
	std::cout << "Cat Destructor called" << std::endl;
	delete this->_brain;
}

/* Public Method */
void	Cat::makeSound( void ) const {
	std::cout << CAT_SOUND_MESSAGE(this->getType()) << std::endl;
}

Brain *Cat::getBrain( void ) const {
	return (this->_brain);
}
