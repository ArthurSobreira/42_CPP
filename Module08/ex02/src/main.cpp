#include "Defines.hpp"
#include "MutantStack.hpp"

namespace Utils {
	template <typename T> void	printStack( MutantStack<T> &mstack ) {
		typename MutantStack<T>::iterator it = mstack.begin();
		typename MutantStack<T>::iterator ite = mstack.end();

		++it;
		--it;
		while (it != ite) {
			std::cout << "[" << *it << "]";
			++it;
		}
		std::cout << std::endl;
	}

	template <typename T> void	printContainer( T &container ) {
		typename T::iterator it = container.begin();

		while (it != container.end()) {
			std::cout << "[" << *it << "]";
			it++;
		}
		std::cout << std::endl;
	}
}

namespace Tests {
	void	repeatChar( char c, int n, std::string color ) {
		for (int i = 0; i < n; i++) {
			std::cout << color << c;
		}
		std::cout << RESET << std::endl;
	}

	void	testSubject( void ) {
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);

		std::cout << COLORIZE(YELLOW, "Stack Top: ") << 
		mstack.top() << std::endl;

		mstack.pop();

		std::cout << COLORIZE(YELLOW, "Stack Size: ") <<
		mstack.size() << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);

		Utils::printStack(mstack);
		std::stack<int> s(mstack);
	}

	void	testDoubleStack( void ) {
		MutantStack<double> mstack;

		mstack.push(5.5);
		mstack.push(17.5);

		std::cout << COLORIZE(YELLOW, "Stack Top: ") << 
		mstack.top() << std::endl;

		mstack.pop();

		std::cout << COLORIZE(YELLOW, "Stack Size: ") <<
		mstack.size() << std::endl;

		mstack.push(3.5);
		mstack.push(5.5);
		mstack.push(737.5);
		mstack.push(0.5);

		Utils::printStack(mstack);
	}

	void	testStringStack( void ) {
		MutantStack<std::string> mstack;

		mstack.push("Hello");
		mstack.push("World");

		std::cout << COLORIZE(YELLOW, "Stack Top: ") << 
		mstack.top() << std::endl;

		mstack.pop();

		std::cout << COLORIZE(YELLOW, "Stack Size: ") <<
		mstack.size() << std::endl;

		mstack.push("This");
		mstack.push("Is");
		mstack.push("A");
		mstack.push("Test");

		MutantStack<std::string> mstack2(mstack);
		Utils::printStack(mstack2);
	}
}

int main( void ){
	Tests::repeatChar('=', 39, BOLD_CYAN);
	std::cout << "             Subject Tests " << std::endl;
	Tests::repeatChar('=', 39, BOLD_CYAN);
	Tests::testSubject();

	Tests::repeatChar('=', 39, BOLD_CYAN);
	std::cout << "           Double Stack Tests " << std::endl;
	Tests::repeatChar('=', 39, BOLD_CYAN);
	Tests::testDoubleStack();

	Tests::repeatChar('=', 39, BOLD_CYAN);
	std::cout << "           String Stack Tests " << std::endl;
	Tests::repeatChar('=', 39, BOLD_CYAN);
	Tests::testStringStack();

	return (0);
}