#include "Defines.hpp"
#include "Sed.hpp"
#include <fstream>

Sed::Sed( std::string target, std::string replacement ) : 
	_target(target), _replacement(replacement) {};

Sed::~Sed( void ) {};

/* Getter and Setter _target */
const std::string	Sed::getTarget( void ) const {
	return (this->_target);
}

void	Sed::setTarget( std::string target ) {
	this->_target = target;
}

/* Getter and Setter _replacement */
const	std::string	Sed::getReplacement( void ) const {
	return (this->_replacement);
}

void	Sed::setReplacement( std::string replacement ) {
	this->_replacement = replacement;
}

/* Public Methods */
void	Sed::replace( std::string filename ) {
	std::ifstream	file(filename.c_str());

	if (!file || file.fail()) {
		std::cout << ERROR_OPEN_FILE(filename) << std::endl;
		return ;
	}
}
