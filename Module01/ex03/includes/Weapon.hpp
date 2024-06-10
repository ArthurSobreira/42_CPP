#ifndef WEAPON_CPP
# define WEAPON_CPP

#include <iostream>

class	Weapon {
	private:
		std::string _type;

	public:
		/* Constructor Method */
		Weapon( std::string type );

		/* Destructor Method */
		~Weapon( void );

		/* Getter and Setter _type */
		const	std::string	getType( void ) const;
		void	setType( std::string type );
};

#endif