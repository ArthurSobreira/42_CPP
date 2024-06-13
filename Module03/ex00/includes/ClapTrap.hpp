#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
	private:
		std::string	_name;
		int		_hitPoints;
		int		_energyPoints;
		int		_attackDamage;

	public:
		/* Constructor Methods */
		ClapTrap( void );
		ClapTrap( const std::string &name );

		/* Copy Constructor Method */
		ClapTrap( const ClapTrap &other );

		/* Copy Assignment Operator Overload */
		ClapTrap &operator=( const ClapTrap &other );
	
		/* Destructor Method */
		~ClapTrap( void );

		/* Getter and Setter _name */
		std::string	getName( void ) const;
		void	setName( std::string name);

		/* Getter and Setter _hitPoints */
		int		getHitPoints( void ) const;
		void	setHitPoints( int hitPoints );

		/* Getter and Setter _energyPoints */
		int		getEnergyPoints( void ) const;
		void	setEnergyPoints( int energyPoints );

		/* Getter and Setter _attackDamage */
		int		getAttackDamage( void ) const;
		void	setAttackDamage( int attackDamage );

		/* Public Methods */
		void	attack( const std::string &target );
		void	takeDamage( unsigned int amount );
		void	beRepaired( unsigned int amount );
};

#endif
