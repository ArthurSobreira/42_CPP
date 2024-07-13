#include "Span.hpp"

/* Constructor Method */
Span::Span( void ) : _size(0) {};

Span::Span( uint size ) : _size(size) {}

/* Copy Constructor Method */
Span::Span( const Span &other ) : _size(0) {
	*this = other;
}

/* Copy Assignment Operator Overload */
Span &Span::operator=( const Span &other ) {
	if ( this != &other ) {
		this->_list = other._list;
		this->_size = other._size;
	}
	return (*this);
}

/* Destructor Method */
Span::~Span( void ) {}

/* Public Methods */
void	Span::addNumber( int number ) {
	if (this->_list.size() >= this->_size)
		throw Span::LimitReachedException();
	this->_list.push_back(number);
}

int	Span::shortestSpan( void ) {
	if (this->_list.size() < 2)
		throw Span::NotEnoughNumbersException();

	std::sort(this->_list.begin(), this->_list.end());
	
	int shortest = this->_list[1] - this->_list[0];
	int current;
	int previous;
	for (uint i = 2; i < this->_list.size(); i++) {
		current = this->_list[i];
		previous = this->_list[i - 1];
		if (current - previous < shortest)
			shortest = current - previous;
	}
	return (std::abs(shortest));
}

int	Span::longestSpan( void ) {
	if (this->_list.size() < 2)
		throw Span::NotEnoughNumbersException();

	int min = *std::min_element(this->_list.begin(), this->_list.end());
	int max = *std::max_element(this->_list.begin(), this->_list.end());
	return (std::abs(max - min));
}

void	Span::populate( std::vector<int>::iterator begin, 
	std::vector<int>::iterator end ) {
	try {
		while (begin != end) {
			this->addNumber(*begin);
			begin++;
		}
	} catch (Span::LimitReachedException &e) {
		std::cout << e.what() << std::endl;
	}
}

/* Exception Classes */
const char *Span::LimitReachedException::what( void ) const throw() {
	return ("Container Limit Reached");
}

const char *Span::NotEnoughNumbersException::what( void ) const throw() {
	return ("Container Has Less Than 2 Numbers");
}
