#include "ClapTrap.hpp"

/* Getter and Setter _name */
std::string	ClapTrap::getName( void ) const {
	return (this->_name);
}

void	ClapTrap::setName( std::string name ) {
	this->_name = name;
}

/* Getter and Setter _hitPoints */
int		ClapTrap::getHitPoints( void ) const {
	return (this->_hitPoints);
}

void	ClapTrap::setHitPoints( int hitPoints ) {
	this->_hitPoints = hitPoints;
}

/* Getter and Setter _energyPoints */
int		ClapTrap::getEnergyPoints( void ) const {
	return (this->_energyPoints);
}

void	ClapTrap::setEnergyPoints( int energyPoints ) {
	this->_energyPoints = energyPoints;
}

/* Getter and Setter _attackDamage */
int		ClapTrap::getAttackDamage( void ) const {
	return (this->_attackDamage);
}

void	ClapTrap::setAttackDamage( int attackDamage ) {
	this->_attackDamage = attackDamage;
}
