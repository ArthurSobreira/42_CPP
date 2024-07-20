#include "Defines.hpp"
#include "RPN.hpp"

namespace RPNUtils {
	bool	isOperator( char c ) {
		return (c == '+' || c == '-' || c == '*' || c == '/');
	}

	bool	isOnlySpaces( std::string expression ) {
		return (expression.find_first_not_of(" ") == std::string::npos);
	}

	bool	isLowerThanTen( std::string expression ) {
		for (size_t i = 0; i < expression.length(); i++) {
			if (isdigit(expression[i]) && expression[i] > '0') {
				if (i + 1 != expression.length() 
					&& isdigit(expression[i + 1])) {
					return (false);
				}
			}
		}
		return (true);
	}

	void	validateExpression( std::string expression ) {
		if (expression.empty() || isOnlySpaces(expression)) {
			throw InvalidExpressionException(EMPTY_EXPRESSION);
		}
		if (expression.find_first_not_of("0123456789 +-*/") 
			!= std::string::npos) {
			throw InvalidExpressionException(INVALID_CHAR);
		}
		if (!isLowerThanTen(expression)) {
			throw InvalidExpressionException(BIGGER_THAN_TEN);
		}
	}
}

/* Constructor Methods */
RPN::RPN( void ) { 
	throw InvalidExpressionException(GENERIC_ERROR); 
}

RPN::RPN( std::string expression) : _expression(expression) {
	RPNUtils::validateExpression(this->_expression);
};

/* Copy Constructor Method */
RPN::RPN( const RPN &other ) {
	*this = other;
}

/* Copy Assignment Operator Overload */
RPN &RPN::operator=( const RPN &other ) {
	if ( this != &other ) {
		this->_expression = other.getExpression();
	}
	return (*this);
}

/* Destructor Method */
RPN::~RPN( void ) {}

/* Public Methods */
std::string	RPN::getExpression( void ) const {
	return (this->_expression);
}

void	RPN::executeOperation( CalcStack &calcStack, char op ) const {
	if (calcStack.size() < 2) {
		throw InvalidOperationException(NOT_ENOUGH_NUMBERS);
	}

	size_t a = calcStack.top();
	calcStack.pop();
	size_t b = calcStack.top();
	calcStack.pop();

	if (op == '/' && a == 0) {
		throw InvalidOperationException(DIVISION_BY_ZERO);
	}

	switch (op) {
		case '+':
			calcStack.push(b + a);
			break;
		case '-':
			calcStack.push(b - a);
			break;
		case '*':
			calcStack.push(b * a);
			break;
		case '/':
			calcStack.push(b / a);
			break;
		default:
			throw InvalidOperationException(GENERIC_ERROR);
	}
}

size_t	RPN::calculate( void ) const {
	std::string	expr = this->getExpression();
	CalcStack	calcStack;

	for (std::string::iterator it = expr.begin(); 
		it != expr.end(); ++it) {
		if (isdigit(static_cast<int>(*it))) {
			calcStack.push(static_cast<size_t>(*it - '0'));
		} else if (*it == ' ') {
			continue;
		} else {
			this->executeOperation(calcStack, *it);
		}
	}

	return (calcStack.top());
}

/* Exception Classes */
const char *InvalidExpressionException::what( void ) const throw() {
	switch (this->_error) {
		case EMPTY_EXPRESSION:
			return (RED "Error: Empty Expression" RESET);
		case INVALID_CHAR:
			return (RED "Error: Invalid Character" RESET);
		case BIGGER_THAN_TEN:
			return (RED "Error: Number Bigger Than 10" RESET);	
		default:
			return (RED "Error: Invalid Expression" RESET);
	}
}

const char *InvalidOperationException::what( void ) const throw() {
	switch (this->_error) {
		case NOT_ENOUGH_NUMBERS:
			return (RED "Error: Not Enough Numbers" RESET);
		case DIVISION_BY_ZERO:
			return (RED "Error: Division By Zero" RESET);
		default:
			return (RED "Error: Invalid Operation" RESET);
	}
}
