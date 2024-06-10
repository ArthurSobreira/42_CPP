#include "Defines.hpp"
#include "Harl.hpp"

Harl::Harl( void ) {};

Harl::~Harl( void ) {};

/* Private Methods */
void	Harl::debug( void ) {
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << MESSAGE_DEBUG << std::endl;
}

void	Harl::info( void ) {
	std::cout << "[ INFO ]" << std::endl;
	std::cout << MESSAGE_INFO << std::endl;
}

void	Harl::warning( void ) {
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << MESSAGE_WARNING << std::endl;
}

void	Harl::error( void ) {
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << MESSAGE_ERROR << std::endl;
}

/* Public Methods */
void	Harl::complain( std::string level ) {
	void	(Harl::*complainLevel[4])( void ) = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};

	for (int i = 0; i < 4; i++) {
		if (level == LEVELS[i]) {
			return ((this->*complainLevel[i])());
		}
	}
	std::cout << ERROR_INVALID_LEVEL << std::endl;
}
