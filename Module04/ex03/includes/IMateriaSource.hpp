#ifndef IMATERIASOURCE_HPP_
#define IMATERIASOURCE_HPP_

#include "AMateria.hpp"
#include <iostream>

class IMateriaSource {
	public:
		virtual ~IMateriaSource( void ) {}
		virtual void learnMateria( AMateria* ) = 0;
		virtual AMateria* createMateria( std::string const & type ) = 0;
};

#endif
