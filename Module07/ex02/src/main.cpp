#include "Defines.hpp"
#include "Array.hpp"
#include <cstdlib>
#include <ctime>

namespace Utils {
    void    fillIntArray( Array<int> &array ) {
        std::srand(std::time(NULL));
        for (uint i = 0; i < array.size(); i++) {
            array[i] = rand() % 100;
        }
    }

    void    fillStringArray( Array<std::string> &array ) {
        std::string strings[] = {
			"Hello", "World", "42", "Cpp", "Module07"
		};
        for (uint i = 0; i < array.size(); i++) {
            array[i] = strings[rand() % 5];
        }
    }

    template <typename T>
    void    printArray( Array<T> &array ) {
        for (uint i = 0; i < array.size(); i++) {
            std::cout << CYAN "Array[" << i << "]: " RESET << 
            array[i] << std::endl;
        }
    }
}

namespace Tests {
	void	repeatChar( char c, int n, std::string color ) {
		for (int i = 0; i < n; i++) {
			std::cout << color << c;
		}
		std::cout << RESET << std::endl;
	}

    void    testValidArray( void ) {
        Array<int> array1(5);

        std::cout << COLORIZE( BLUE, "Array1 size: " ) << 
        array1.size() << std::endl;
        Utils::fillIntArray(array1);
        Utils::printArray(array1);

        Array<std::string> array2(5);

        std::cout << COLORIZE( BLUE, "Array2 size: " ) <<
        array2.size() << std::endl;
        Utils::fillStringArray(array2);
        Utils::printArray(array2);
    }

    void    testInvalidArray( void ) {
        Array<int> array1(2);
		Array<std::string> array2;

		try {
			array2[0] = "Hello";
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}

		try {
			array1[10] = 42;
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
    }
}

int main( void ){
    Tests::repeatChar( '=', 36, BOLD_CYAN );
    std::cout << "         Valid Array Tests " << std::endl;
    Tests::repeatChar( '=', 36, BOLD_CYAN );
    Tests::testValidArray();

    Tests::repeatChar( '=', 36, BOLD_CYAN );
    std::cout << "        Invalid Array Tests " << std::endl;
    Tests::repeatChar( '=', 36, BOLD_CYAN );
    Tests::testInvalidArray();

    return (0);
}
