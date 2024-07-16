#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <algorithm>
#include <iostream>
#include <stack>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T> {	
	public:
		/* Iterator Typedefs */
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;

		/* Constructor Method */
		MutantStack( void );
		
		/* Copy Constructor Method */
		MutantStack( const MutantStack &other );
		
		/* Copy Assignment Operator Overload */
		MutantStack<T> &operator=( const MutantStack &other );
		
		/* Destructor Method */
		~MutantStack( void );
		
		/* Public Methods */
		iterator begin( void );
		iterator end( void );
		const_iterator begin( void ) const;
		const_iterator end( void ) const;
};

#include "../src/MutantStack.tpp"

#endif
