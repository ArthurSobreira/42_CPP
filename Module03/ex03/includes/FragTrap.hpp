#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class FragTrap : virtual public ClapTrap {
	public:
		/* Constructor Methods */
		FragTrap( void );
		FragTrap( const std::string &name );

		/* Copy Constructor Method */
		FragTrap( const FragTrap &other );

		/* Copy Assignment Operator Overload */
		FragTrap &operator=( const FragTrap &other );

		/* Destructor Method */
		~FragTrap( void );

		/* Public Methods */
		void	highFivesGuys( void );
};

#endif
