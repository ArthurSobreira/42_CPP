#include "Defines.hpp"
#include "PmergeMe.hpp"

namespace Utils {
	template <typename T> void	printContainer( T &container ) {
		typename T::iterator it = container.begin();

		while (it != container.end()) {
			std::cout << *it << " ";
			it++;
		}
		std::cout << std::endl;
	}

	void	printTimeElapsed( size_t size, double elapsed, bool isVector ) {
		if (isVector) {
			std::cout << "Time to process a range of " << size << 
			"elements with std::vector: " << std::fixed << 
			std::setprecision(6) << elapsed << " us" << std::endl;
		} else {
			std::cout << "Time to process a range of " << size << 
			"elements with std::deque: " << std::fixed << 
			std::setprecision(6) << elapsed << " us" << std::endl;
		}
	}
}

int main( int argc, char *argv[] ) {
	if (argc == 1) {
		std::cout << COLORIZE(RED, "Usage: ./PmergeMe [expression]") << std::endl;
		return (1);
	}

	Vector	unsortedVector;
	Deque	unsortedDeque;
	Vector	sortedVector;
	Deque	sortedDeque;

	for (int i = 1; i < argc; i++) {
		unsortedVector.push_back(std::atoi(argv[i]));
		unsortedDeque.push_back(std::atoi(argv[i]));
	}

	try {
		PmergeMe	pmergeMe(unsortedVector);

		std::clock_t start = std::clock();
		sortedVector = pmergeMe.fordJohnsonSort(unsortedVector);
		std::clock_t end = std::clock();
		double elapsedVector = double(end - start) / CLOCKS_PER_SEC;
		
		PmergeMe	pmergeMe2(unsortedDeque);

		std::clock_t start2 = std::clock();
		sortedDeque = pmergeMe2.fordJohnsonSort(unsortedDeque);
		std::clock_t end2 = std::clock();
		double elapsedDeque = double(end2 - start2) / CLOCKS_PER_SEC;

		std::cout << COLORIZE(CYAN, "Before Sorting: ");
		Utils::printContainer(unsortedVector);
		std::cout << COLORIZE(GREEN, "After Sorting: ");
		Utils::printContainer(sortedVector);

		Utils::printTimeElapsed(unsortedVector.size(), elapsedVector, true);
		Utils::printTimeElapsed(unsortedDeque.size(), elapsedDeque, false);

	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
		return (1);
	}

	return (0);
}