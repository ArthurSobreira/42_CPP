#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Data.hpp"
#include <iostream>
#include <stdint.h>

class Serializer {
	private:
		/* Constructor Method */
		Serializer( void );
		
		/* Copy Constructor Method */
		Serializer( const Serializer &other );
		
		/* Copy Assignment Operator Overload */
		Serializer &operator=( const Serializer &other );
		
		/* Destructor Method */
		~Serializer( void );
		
	public:
		/* Public Methods */
		static uintptr_t	serialize( Data *ptr );
		static Data	*deserialize( uintptr_t raw );
};

#endif
