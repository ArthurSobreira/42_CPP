#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClaTrap.hpp"
#include <iostream>

class ScavTrap : public ClapTrap {
	public:
		/* Constructor Methods */
		ScavTrap( void );
		ScavTrap( const std::string &name );

		/* Copy Constructor Method */
		ScavTrap( const ScavTrap &other );

		/* Copy Assignment Operator Overload */
		ScavTrap &operator=( const ScavTrap &other );

		/* Destructor Method */
		~ScavTrap( void );

		/* Public Methods */
		void	attack( const std::string &target );
		void	guardGate( void );
};

#endif
