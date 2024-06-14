#include "Defines.hpp"
#include "DiamondTrap.hpp"

/* Constructor Methods */
DiamondTrap::DiamondTrap( void ) : FragTrap(), ScavTrap() {
	std::cout << "DiamondTrap Default Constructor called" << std::endl;
	this->_name = "Default";
	ClapTrap::_name = std::string("Default") + "_clap_name";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 30;
}

DiamondTrap::DiamondTrap( const std::string &name ) : ClapTrap( name + "_clap_name" ), 
	FragTrap( name + "_clap_name" ), ScavTrap( name + "_clap_name" ) {
	std::cout << "DiamondTrap Name Constructor called" << std::endl;
	this->_name = name;
	ClapTrap::_name = name + "_clap_name";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 30;
}

/* Copy Constructor Method */
DiamondTrap::DiamondTrap( const DiamondTrap &other ) : ClapTrap( other ), 
	FragTrap( other ), ScavTrap( other ) {
	std::cout << "DiamondTrap Copy Constructor called" << std::endl;
	*this = other;
}

/* Copy Assignment Operator Overload */
DiamondTrap &DiamondTrap::operator=( const DiamondTrap &other ) {
	std::cout << "DiamondTrap Copy Assignment Operator called" << std::endl;
	if (this != &other) {
		this->_name = other.getName();
		this->_hitPoints = other.getHitPoints();
		this->_energyPoints = other.getEnergyPoints();
		this->_attackDamage = other.getAttackDamage();
	}
	return (*this);
}

/* Destructor Method */
DiamondTrap::~DiamondTrap( void ) {
	std::cout << "DiamondTrap Destructor called" << std::endl;
}

/* Getter and Setter _name */
std::string	DiamondTrap::getName( void ) const {
	return (this->_name);
}

void	DiamondTrap::setName( std::string name ) {
	this->_name = name;
}

/* Public Methods */
void	DiamondTrap::attack( const std::string &target ) {
	ScavTrap::attack( target );
}

void	DiamondTrap::whoAmI( void ) {
	std::cout << WHO_AM_I_MESSAGE(this->getName(), ClapTrap::_name) << std::endl;
}
