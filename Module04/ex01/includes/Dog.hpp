#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Dog : public Animal {
	private:
		Brain *_brain;

	public:
		/* Constructor Method */
		Dog( void );

		/* Copy Constructor Method */
		Dog( const Dog &other );

		/* Copy Assignment Operator Overload */
		Dog &operator=( const Dog &other );

		/* Destructor Method */
		~Dog( void );

		/* Public Method */
		void makeSound( void ) const;
		Brain *getBrain( void ) const;
};

#endif
