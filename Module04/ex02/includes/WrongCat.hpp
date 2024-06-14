#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include <iostream>

class WrongCat : public WrongAnimal {
	public:
		/* Constructor Method */
		WrongCat( void );

		/* Copy Constructor Method */
		WrongCat( const WrongCat &other );

		/* Copy Assignment Operator Overload */
		WrongCat &operator=( const WrongCat &other );

		/* Destructor Method */
		~WrongCat( void );

		/* Public Method */
		void makeSound( void ) const;
};

#endif
