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

	void	animalTest( void ) {
		const Animal* animal = new Animal();
		const Animal* dog = new Dog();
		const Animal* cat = new Cat();

		std::cout << dog->getType() << " " << std::endl;
		std::cout << cat->getType() << " " << std::endl;
		dog->makeSound();
		cat->makeSound();
		animal->makeSound();

		delete animal;
		delete dog;
		delete cat;
	}

	void	wrongAnimalTest( void ) {
		const WrongAnimal* wrongAnimal = new WrongAnimal();
		const WrongAnimal* wrongCat = new WrongCat();

		std::cout << wrongCat->getType() << " " << std::endl;
		wrongCat->makeSound();
		wrongAnimal->makeSound();

		delete wrongAnimal;
		delete wrongCat;
	}
}

int main( void ) {
	Tests::repeatChar('=', 31, CYAN);
	std::cout << "          Animal Test" << std::endl;
	Tests::repeatChar('=', 31, CYAN);
	Tests::animalTest();

	Tests::repeatChar('=', 36, CYAN);
	std::cout << "          WrongAnimal Test" << std::endl;
	Tests::repeatChar('=', 36, CYAN);
	Tests::wrongAnimalTest();

	return (0);
}
