#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria {
	public:
		/* Constructor Method */
		Cure( void );

		/* Copy Constructor Method */
		Cure( const Cure &other );

		/* Copy Assignment Operator Overload */
		Cure &operator=( const Cure &other );

		/* Destructor Method */
		~Cure( void );

		/* Public Method */
		AMateria *clone( void ) const;
		void use( ICharacter &target );
};

#endif
