#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stdexcept>
#include <stack>

class RPN {
	private:
		std::string	_expression;

	public:
		/* Constructor Methods */
		RPN( void );
		RPN( std::string expression );

		/* Copy Constructor Method */
		RPN( const RPN &other );

		/* Copy Assignment Operator Overload */
		RPN &operator=( const RPN &other );
		
		/* Destructor Method */
		~RPN( void );
		
		/* Public Methods */
		size_t	calculate( void ) const;
};

#endif
