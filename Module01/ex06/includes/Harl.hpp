#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>

class Harl {
	private:
		void	debug( void );
		void	info( void );
		void	warning( void );
		void	error( void );

	public:
		/* Constructor Method */
		Harl( void );

		/* Destructor Method */
		~Harl( void );

		/* Public Methods */
		void	complain( std::string level );
};

#endif