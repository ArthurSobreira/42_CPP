#include "Serializer.hpp"

/* Constructor Method */
Serializer::Serializer( void ) {};

/* Copy Constructor Method */
Serializer::Serializer( const Serializer &other ) {
	*this = other;
}

/* Copy Assignment Operator Overload */
Serializer &Serializer::operator=( const Serializer &other ) {
	(void)other;
	return (*this);
}

/* Destructor Method */
Serializer::~Serializer( void ) {}

/* Public Methods */
uintptr_t	Serializer::serialize( Data *ptr ) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data	*Serializer::deserialize( uintptr_t raw ) {
	return (reinterpret_cast<Data *>(raw));
}
