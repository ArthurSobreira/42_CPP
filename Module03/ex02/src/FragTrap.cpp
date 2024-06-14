#include "Defines.hpp"
#include "FragTrap.hpp"

/* Constructor Methods */
FragTrap::FragTrap( void ) : ClapTrap() {
	std::cout << "FragTrap Default Constructor called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap( const std::string &name ) : ClapTrap( name ) {
	std::cout << "FragTrap Name Constructor called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

/* Copy Constructor Method */
FragTrap::FragTrap( const FragTrap &other ) : ClapTrap( other ) {
	std::cout <<  "FragTrap Copy Constructor called" << std::endl;
	*this = other;
}

/* Copy Assignment Operator Overload */
FragTrap &FragTrap::operator=( const FragTrap &other ) {
	std::cout << "FragTrap Copy Assignment Operator called" << std::endl;
	if (this != &other) {
		this->_name = other.getName();
		this->_hitPoints = other.getHitPoints();
		this->_energyPoints = other.getEnergyPoints();
		this->_attackDamage = other.getAttackDamage();
	}
	return (*this);
}

/* Destructor Method */
FragTrap::~FragTrap( void ) {
	std::cout << "FragTrap Destructor called" << std::endl;
}

/* Public Methods */
void	FragTrap::highFivesGuys( void ) {
	std::cout << HIGH_FIVES_MESSAGE(this->getName()) << std::endl;
}

