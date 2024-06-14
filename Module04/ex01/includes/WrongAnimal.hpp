#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {
	protected:
		std::string _type;

	public:
		/* Constructor Method */
		WrongAnimal( void );

		/* Copy Constructor Method */
		WrongAnimal( const WrongAnimal &other );

		/* Copy Assignment Operator Overload */
		WrongAnimal &operator=( const WrongAnimal &other );

		/* Destructor Method */
		~WrongAnimal( void );

		/* Getter and Setter _type */
		std::string getType( void ) const;
		void setType( std::string type );

		/* Public Method */
		void makeSound( void ) const;  
};

#endif
