#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <iostream>

class Character : public ICharacter {
	private:
		std::string _name;
		AMateria *_inventory[4];
		
	public:
		/* Constructor Method */
		Character( void );
		Character( std::string const &name );

		/* Copy Constructor Method */
		Character( const Character &other );

		/* Copy Assignment Operator Overload */
		Character &operator=( const Character &other );

		/* Destructor Method */
		~Character( void );

		/* Getter _name Method */
		std::string const &getName( void ) const;

		/* Public Method */
		void equip( AMateria *m );
		void unequip( int idx );
		void use( int idx, ICharacter &target );
};

#endif
