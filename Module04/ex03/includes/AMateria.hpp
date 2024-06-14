#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>

class ICharacter;

class AMateria {
	protected:
		std::string _type;

	public:
		/* Constructor Method */
		AMateria( void );
		AMateria( std::string const &type );

		/* Copy Constructor Method */
		AMateria( const AMateria &other );

		/* Copy Assignment Operator Overload */
		AMateria &operator=( const AMateria &other );

		/* Destructor Method */
		virtual ~AMateria( void );

		/* Getter _type Method */
		std::string const &getType( void ) const;
		
		/* Public Method */
		virtual AMateria *clone() const = 0;
		virtual void use( ICharacter& target );
};

#endif
