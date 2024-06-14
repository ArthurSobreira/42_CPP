#include "Defines.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

namespace Tests {
	void	repeatChar( char c, int n, std::string color ) {
		for (int i = 0; i < n; i++) {
			std::cout << color << c;
		}
		std::cout << RESET << std::endl;
	}

	static void	printAnimalsIdeas( const Animal *animals[], int n) {
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
		const Animal *animals[4] = {
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

	void	testDeepCopyCat( void ) {
		Cat cat1;
		Cat cat2 = cat1;

		std::cout << std::endl;
		std::cout << "Original and copied Cat objects after copy:" << std::endl;
		std::cout << "cat1 Brain address: " << cat1.getBrain() << std::endl;
		std::cout << "cat2 Brain address: " << cat2.getBrain() << std::endl;

		cat2.getBrain()->setIdea(0, "New idea for cat2");

		std::cout << "Original and copied Cat objects after modification:" << std::endl;
		std::cout << "cat1 Brain idea: " << cat1.getBrain()->getIdea(0) << std::endl;
		std::cout << "cat2 Brain idea: " << cat2.getBrain()->getIdea(0) << std::endl;
		std::cout << std::endl;
	}

	void	testDeepCopyDog( void ) {
		Dog dog1;
		Dog dog2 = dog1;

		std::cout << std::endl;
		std::cout << "Original and copied Dog objects after copy:" << std::endl;
		std::cout << "dog1 Brain address: " << dog1.getBrain() << std::endl;
		std::cout << "dog2 Brain address: " << dog2.getBrain() << std::endl;

		dog2.getBrain()->setIdea(0, "New idea for dog2");

		std::cout << "Original and copied Dog objects after modification:" << std::endl;
		std::cout << "dog1 Brain idea: " << dog1.getBrain()->getIdea(0) << std::endl;
		std::cout << "dog2 Brain idea: " << dog2.getBrain()->getIdea(0) << std::endl;
		std::cout << std::endl;
	}
}

int main( void ) {
	Tests::repeatChar('=', 37, CYAN);
	std::cout << "          Animal Array Test" << std::endl;
	Tests::repeatChar('=', 37, CYAN);
	Tests::testAnimalArray();

	Tests::repeatChar('=', 40, CYAN);
	std::cout << "          Deep Copy Test (Cat)" << std::endl;
	Tests::repeatChar('=', 40, CYAN);
	Tests::testDeepCopyCat();

	Tests::repeatChar('=', 40, CYAN);
	std::cout << "          Deep Copy Test (Dog)" << std::endl;
	Tests::repeatChar('=', 40, CYAN);
	Tests::testDeepCopyDog();

	return (0);
}
