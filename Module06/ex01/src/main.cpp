#include "Defines.hpp"
#include "Serializer.hpp"

namespace Tests {
	void	repeatChar( char c, int n, std::string color ) {
		for (int i = 0; i < n; i++) {
			std::cout << color << c;
		}
		std::cout << RESET << std::endl;
	}

	void	testSerializeDataValue( void ) {
		Data		*data = new Data(4242);
		uintptr_t	raw = Serializer::serialize(data);
		Data		*data_copy = Serializer::deserialize(raw);

		std::cout << COLORIZE(YELLOW, "Data Value:      ") << 
		data->getAttribute() << std::endl;
		std::cout << COLORIZE(YELLOW, "Data_copy Value: ") << 
		data_copy->getAttribute() << std::endl;

		delete data;
	}

	void	testSerializeDataAddress( void ) {
		Data		*data = new Data(4242);
		uintptr_t	raw = Serializer::serialize(data);
		Data		*data_copy = Serializer::deserialize(raw);

		std::cout << COLORIZE(YELLOW, "Data Address:      ") << 
		data << std::endl;
		std::cout << COLORIZE(YELLOW, "Data_copy Address: ") << 
		data_copy << std::endl;

		delete data;
	}
}

int main( void ) {
	Tests::repeatChar('=', 51, CYAN);
	std::cout << "     Test Serialize and Deserialize Data Value " << std::endl;
	Tests::repeatChar('=', 51, CYAN);
	Tests::testSerializeDataValue();

	Tests::repeatChar('=', 51, CYAN);
	std::cout << "    Test Serialize and Deserialize Data Address" << std::endl;
	Tests::repeatChar('=', 51, CYAN);
	Tests::testSerializeDataAddress();

	return (0);
}
