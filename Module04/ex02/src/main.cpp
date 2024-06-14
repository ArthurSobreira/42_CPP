#include "Defines.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

namespace Tests {
	void	repeatChar( char c, int n, std::string color ) {
		for (int i = 0; i < n; i++) {
			std::cout << color << c;
		}
		std::cout << RESET << std::endl;
	}

	static void	printAnimalsIdeas( const AAnimal *animals[], int n) {
		for (int i = 0; i < n; i++) {
			animals[i]->makeSound();
			const Cat	*cat = dynamic_cast<const Cat*>(animals[i]);
			if (cat != NULL) {
				std::cout << cat->getType() << " Idea: " \
				<< COLORIZE(MAGENTA, cat->getBrain()->getIdea(0)) << std::endl;
			} else {
				const Dog	*dog = dynamic_cast<const Dog*>(animals[i]);
				if (dog != NULL) {
					std::cout << dog->getType() << " Idea: " \
					<< COLORIZE(BLUE, dog->getBrain()->getIdea(0)) << std::endl;
				}
			}
		}
	}

	void	testAnimalArray( void ) {
		const AAnimal *animals[4] = {
			new Cat(), new Dog(),
			new Cat(), new Dog()
		};

		for (int i = 0; i < 4; i++) {
			if (i % 2 == 0) {
				const Cat	*cat = dynamic_cast<const Cat*>(animals[i]);
				if (cat != NULL)
					cat->getBrain()->setIdea(0, "Give me a fish");
			} else {
				const Dog	*dog = dynamic_cast<const Dog*>(animals[i]);
				if (dog != NULL)
					dog->getBrain()->setIdea(0, "Give me a bone");
			}
		}

		std::cout << std::endl;
		printAnimalsIdeas(animals, 4);
		std::cout << std::endl;

		for (int i = 0; i < 4; i++) {
			delete animals[i];
		}
	}
}

int main( void ) {
	Tests::repeatChar('=', 37, CYAN);
	std::cout << "          Animal Array Test" << std::endl;
	Tests::repeatChar('=', 37, CYAN);
	Tests::testAnimalArray();

	/* AAnimal animal;  // This will cause a compile error

	animal.makeSound(); */
	return (0);
}
