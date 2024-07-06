#include "Defines.hpp"
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

/* Destructor Method */
Base::~Base( void ) {}

/* Base Functions */
Base	*generate( void ) {
	static bool	first = true;

	if (first) {
		std::srand(std::time(NULL));
		first = false;
	}

	short	random = std::rand() % 3;

	switch (random) {
		case 0:
			return (new A());
		case 1:
			return (new B());
		case 2:
			return (new C());
		default:
			return (NULL);
	}
}

void	identify( Base *p ) {
	if (dynamic_cast<A *>(p) != NULL) {
		std::cout << "A" << std::endl;
	} else if (dynamic_cast<B *>(p) != NULL) {
		std::cout << "B" << std::endl;
	} else if (dynamic_cast<C *>(p) != NULL) {
		std::cout << "C" << std::endl;
	} else {
		std::cout << COLORIZE(RED, "Unknown") << std::endl;
	}
}

void	identify( Base &p ) {
	try {
		A &a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << "A" << std::endl;
	} catch (std::exception &e1) {
		try {
			B &b = dynamic_cast<B &>(p);
			(void)b;
			std::cout << "B" << std::endl;
		} catch (std::exception &e2) {
			try {
				C &c = dynamic_cast<C &>(p);
				(void)c;
				std::cout << "C" << std::endl;
			} catch (std::exception &e3) {
				std::cout << COLORIZE(RED, "Unknown") << std::endl;
			}
		}
	}
}
