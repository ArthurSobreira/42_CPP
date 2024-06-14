#include "Defines.hpp"
#include "ClapTrap.hpp"

/* Constructor Methods */
ClapTrap::ClapTrap( void ) : _name("Guest"), _hitPoints(10), 
	_energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap Default Constructor called" << std::endl;
}

ClapTrap::ClapTrap( const std::string &name ) : _name(name),
	_hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap Name Constructor called" << std::endl;
}

/* Copy Constructor Method */
ClapTrap::ClapTrap( const ClapTrap &other ) {
	std::cout <<  "ClapTrap Copy Constructor called" << std::endl;
	*this = other;
}

/* Copy Assignment Operator Overload */
ClapTrap &ClapTrap::operator=( const ClapTrap &other ) {
	std::cout << "ClapTrap Copy Assignment Operator called" << std::endl;
	if (this != &other) {
		this->_name = other.getName();
		this->_hitPoints = other.getHitPoints();
		this->_energyPoints = other.getEnergyPoints();
		this->_attackDamage = other.getAttackDamage();
	}
	return (*this);
}

/* Destructor Method */
ClapTrap::~ClapTrap ( void ) {
	std::cout << "ClapTrap Destructor called" << std::endl;
}

/* Public Methods */
void	ClapTrap::attack( const std::string &target ) {
	if (this->getEnergyPoints() == 0) {
		std::cout << NO_ENERGY_MESSAGE(this->getName()) << std::endl;
		return ;
	}
	else if (this->getHitPoints() == 0) {
		std::cout << ALREADY_DEAD_MESSAGE(this->getName()) << std::endl;
		return ;
	}
	std::cout << ATTACK_MESSAGE(this->getName(), target, \
	this->getAttackDamage()) << std::endl;
	this->setEnergyPoints(this->getEnergyPoints() - 1);
}

void	ClapTrap::takeDamage( unsigned int amount ) {
	if (this->getHitPoints() == 0) {
		std::cout << ALREADY_DEAD_MESSAGE(this->getName()) << std::endl;
		return ;
	}
	std::cout << TAKE_DAMAGE_MESSAGE(this->getName(), amount) << std::endl;
	this->setHitPoints(this->getHitPoints() - amount);
	if (this->getHitPoints() <= 0) {
		std::cout << DEATH_MESSAGE(this->getName()) << std::endl;
		this->setHitPoints(0);
	}
}

void	ClapTrap::beRepaired( unsigned int amount ) {
	if (this->getEnergyPoints() == 0) {
		std::cout << NO_ENERGY_MESSAGE(this->getName()) << std::endl;
		return ;
	}
	else if (this->getHitPoints() == 0) {
		std::cout << ALREADY_DEAD_MESSAGE(this->getName()) << std::endl;
		return ;
	}
	std::cout << BE_REPAIRED_MESSAGE(this->getName(), amount) << std::endl;
	this->setHitPoints(this->getHitPoints() + amount);
	this->setEnergyPoints(this->getEnergyPoints() - 1);
}
