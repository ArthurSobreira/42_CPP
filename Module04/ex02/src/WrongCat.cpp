#include "Defines.hpp"
#include "WrongCat.hpp"

/* Constructor Method */
WrongCat::WrongCat( void ) : WrongAnimal() {
	std::cout << "WrongCat Default Constructor called" << std::endl;
	this->setType("WrongCat");
}

/* Copy Constructor Method */
WrongCat::WrongCat( const WrongCat &other ) : WrongAnimal(other) {
	std::cout << "WrongCat Copy Constructor called" << std::endl;
	*this = other;
}

/* Copy Assignment Operator Overload */
WrongCat &WrongCat::operator=( const WrongCat &other ) {
	std::cout << "WrongCat Copy Assignment Operator called" << std::endl;
	if (this != &other) {
		this->_type = other.getType();
	}
	return (*this);
}

/* Destructor Method */
WrongCat::~WrongCat( void ) {
	std::cout << "WrongCat Destructor called" << std::endl;
}

/* Public Method */
void	WrongCat::makeSound( void ) const {
	std::cout << WRONGCAT_SOUND_MESSAGE(this->getType()) << std::endl;
}
