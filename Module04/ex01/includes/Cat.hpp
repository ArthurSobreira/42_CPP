#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Cat : public Animal {
	private:
		Brain *_brain;

	public:
		/* Constructor Method */
		Cat( void );

		/* Copy Constructor Method */
		Cat( const Cat &other );

		/* Copy Assignment Operator Overload */
		Cat &operator=( const Cat &other );

		/* Destructor Method */
		~Cat( void );

		/* Public Method */
		void makeSound( void ) const;
		Brain *getBrain( void ) const;
};

#endif
