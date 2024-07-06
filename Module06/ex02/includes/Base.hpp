#ifndef BASE_HPP
#define BASE_HPP

class Base {
	public:
		/* Destructor Method */
		~Base( void );
};

/* Base Functions */
Base	*generate( void );
void	identify( Base *p );
void	identify( Base &p );

#endif
