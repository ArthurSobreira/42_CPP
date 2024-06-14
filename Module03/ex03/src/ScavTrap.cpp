#include "Defines.hpp"
#include "ScavTrap.hpp"

/* Constructor Methods */
ScavTrap::ScavTrap( void ) : ClapTrap() {
	std::cout << "ScavTrap Default Constructor called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap( const std::string &name ) : ClapTrap( name ) {
	std::cout << "ScavTrap Name Constructor called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

/* Copy Constructor Method */
ScavTrap::ScavTrap( const ScavTrap &other ) : ClapTrap( other ) {
	std::cout <<  "ScavTrap Copy Constructor called" << std::endl;
	*this = other;
}

/* Copy Assignment Operator Overload */
ScavTrap &ScavTrap::operator=( const ScavTrap &other ) {
	std::cout << "ScavTrap Copy Assignment Operator called" << std::endl;
	if (this != &other) {
		this->_name = other.getName();
		this->_hitPoints = other.getHitPoints();
		this->_energyPoints = other.getEnergyPoints();
		this->_attackDamage = other.getAttackDamage();
	}
	return (*this);
}

/* Destructor Method */
ScavTrap::~ScavTrap( void ) {
	std::cout << "ScavTrap Destructor called" << std::endl;
}

/* Public Methods */
void	ScavTrap::attack( const std::string &target ) {
	if (this->getEnergyPoints() == 0) {
		std::cout << NO_ENERGY_MESSAGE(this->getName()) << std::endl;
		return ;
	}
	std::cout << ST_ATTACK_MESSAGE(this->getName(), target, \
	this->getAttackDamage()) << std::endl;
	this->setEnergyPoints(this->getEnergyPoints() - 1);
}

void	ScavTrap::guardGate( void ) {
	std::cout << GUARD_GATE_MESSAGE(this->getName()) << std::endl;
}
