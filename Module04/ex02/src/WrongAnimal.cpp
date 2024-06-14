#include "Defines.hpp"
#include "WrongAnimal.hpp"

/* Constructor Method */
WrongAnimal::WrongAnimal( void ) : _type("WrongAnimal"){
	std::cout << "WrongAnimal Default Constructor called" << std::endl;
}

/* Copy Constructor Method */
WrongAnimal::WrongAnimal( const WrongAnimal &other ) {
	std::cout << "WrongAnimal Copy Constructor called" << std::endl;
	*this = other;
}

/* Copy Assignment Operator Overload */
WrongAnimal &WrongAnimal::operator=( const WrongAnimal &other ) {
	std::cout << "WrongAnimal Copy Assignment Operator called" << std::endl;
	if (this != &other) {
		this->_type = other.getType();
	}
	return (*this);
}

/* Destructor Method */
WrongAnimal::~WrongAnimal( void ) {
	std::cout << "WrongAnimal Destructor called" << std::endl;
}

/* Getter and Setter _type */
std::string WrongAnimal::getType( void ) const {
	return (this->_type);
}

void	WrongAnimal::setType( std::string type ) {
	this->_type = type;
}

/* Public Method */
void	WrongAnimal::makeSound( void ) const {
	std::cout << WRONGANIMAL_SOUND_MESSAGE(this->getType()) << std::endl;
}
