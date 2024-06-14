#include "AMateria.hpp"
#include "MateriaSource.hpp"

/* Constructor Method */
MateriaSource::MateriaSource( void ) {
	std::cout << "MateriaSource Default Constructor called" << std::endl;
	for ( int i = 0; i < 4; i++ ) {
		this->_materia[i] = NULL;
	}
}

/* Copy Constructor Method */
MateriaSource::MateriaSource( const MateriaSource &other ) {
	std::cout << "MateriaSource Copy Constructor called" << std::endl;
	for ( int i = 0; i < 4; i++ ) {
		this->_materia[i] = other._materia[i]->clone();
	}
}

/* Copy Assignment Operator Overload */
MateriaSource &MateriaSource::operator=( const MateriaSource &other ) {
	std::cout << "MateriaSource Copy Assignment Operator called" << std::endl;
	if (this != &other) {
		for ( int i = 0; i < 4; i++ ) {
			if (other._materia[i]) {
				this->_materia[i] = other._materia[i]->clone();
			} else {
				this->_materia[i] = NULL;
			}
		}
	}
	return (*this);
}

/* Destructor Method */
MateriaSource::~MateriaSource( void ) {
	std::cout << "MateriaSource Destructor called" << std::endl;
	for ( int i = 0; i < 4; i++ ) {
		if (this->_materia[i]) {
			delete this->_materia[i];
		}
	}
}

/* Public Method */
void	MateriaSource::learnMateria( AMateria *m ) {
	for ( int i = 0; i < 4; i++ ) {
		if (!this->_materia[i]) {
			this->_materia[i] = m;
			if (m) {
				std::cout << "AMateria " << m->getType() \
				<< " learned" << std::endl;
			}
			return ;
		}
	}
	std::cout << "MateriaSource is full" << std::endl;
	if (m) {
		delete m;
	}
}

AMateria *MateriaSource::createMateria( std::string const &type ) {
	for ( int i = 0; i < 4; i++ ) {
		if (this->_materia[i] && this->_materia[i]->getType() == type) {
			return (this->_materia[i]->clone());
		}
	}
	std::cout << "Could not create Materia " << type << std::endl;
	return (0);
}
