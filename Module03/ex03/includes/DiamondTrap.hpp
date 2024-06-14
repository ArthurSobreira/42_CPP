#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

class DiamondTrap : public FragTrap, public ScavTrap {
	private:
		std::string	_name;

	public:
		/* Constructor Methods */
		DiamondTrap( void );
		DiamondTrap( const std::string &name );

		/* Copy Constructor Method */
		DiamondTrap( const DiamondTrap &other );

		/* Copy Assignment Operator Overload */
		DiamondTrap &operator=( const DiamondTrap &other );

		/* Destructor Method */
		~DiamondTrap( void );

		/* Getter and Setter _name */
		std::string	getName( void ) const;
		void	setName( std::string name );

		/* Public Methods */
		void	attack( const std::string &target );
		void	whoAmI( void );
};

#endif 
