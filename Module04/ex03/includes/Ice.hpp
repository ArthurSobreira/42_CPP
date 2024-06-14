#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria {
	public:
		/* Constructor Method */
		Ice( void );

		/* Copy Constructor Method */
		Ice( const Ice &other );

		/* Copy Assignment Operator Overload */
		Ice &operator=( const Ice &other );

		/* Destructor Method */
		~Ice( void );

		/* Public Method */
		AMateria *clone( void ) const;
		void use( ICharacter &target );
};

#endif
