#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie {
	private:
		std::string _name;

	public:
		/* Constructor Method */
		Zombie( void );

		/* Destructor Method */
		~Zombie( void );

		/* Getter and Setter _name */
		std::string	getName( void ) const;
		void		setName( std::string name );

		/* Public Methods */
		void	announce( void );
};

#endif