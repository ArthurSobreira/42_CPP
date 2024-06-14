#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain {
	private:
		std::string _ideas[100];

	public:
		/* Constructor Method */
		Brain( void );

		/* Copy Constructor Method */
		Brain( const Brain &other );

		/* Copy Assignment Operator Overload */
		Brain &operator=( const Brain &other );

		/* Destructor Method */
		~Brain( void );

		/* Getter and Setter _ideas */
		std::string getIdea( int index ) const;
		void setIdea( int index, std::string idea );
};

#endif
