#include "Defines.hpp"
#include "Brain.hpp"

/* Constructor Method */
Brain::Brain( void ) {
	std::cout << "Brain Default Constructor called" << std::endl;
	for (int i = 0; i < 100; i++) {
		this->_ideas[i] = "";
	}
}

/* Copy Constructor Method */
Brain::Brain( const Brain &other ) {
	std::cout << "Brain Copy Constructor called" << std::endl;
	*this = other;
}

/* Copy Assignment Operator Overload */
Brain &Brain::operator=( const Brain &other ) {
	std::cout << "Brain Copy Assignment Operator called" << std::endl;
	if (this != &other) {
		for (int i = 0; i < 100; i++) {
			this->_ideas[i] = other._ideas[i];
		}
	}
	return (*this);
}

/* Destructor Method */
Brain::~Brain( void ) {
	std::cout << "Brain Destructor called" << std::endl;
}

/* Getter and Setter _ideas */
std::string Brain::getIdea( int index ) const {
	if (index < 0 || index >= 100) {
		return ("");
	}
	return (this->_ideas[index]);
}

void Brain::setIdea( int index, std::string idea ) {
	if (index < 0 || index >= 100) {
		return ;
	}
	this->_ideas[index] = idea;
}
