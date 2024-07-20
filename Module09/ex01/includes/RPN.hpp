#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stdexcept>
#include <stack>

typedef enum errors {
	GENERIC_ERROR = 1,
	EMPTY_EXPRESSION,
	INVALID_CHAR,
	BIGGER_THAN_TEN,
	NOT_ENOUGH_NUMBERS,
	DIVISION_BY_ZERO
} errorType;

typedef std::stack<size_t>	CalcStack;

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
		std::string	getExpression( void ) const;
		void	executeOperation( CalcStack &calcStack, 
			char op ) const;
		size_t	calculate( void ) const;
};

/* Exception Classes */
class InvalidExpressionException : public std::exception {
	private:
		errorType	_error;

	public:
		InvalidExpressionException( errorType error );

		virtual const char *what( void ) const throw();
};

class InvalidOperationException : public std::exception {
	private:
		errorType	_error;

	public:
		InvalidOperationException( errorType error );

		virtual const char *what( void ) const throw();
};

#endif
