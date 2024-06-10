#include "Defines.hpp"
#include "Harl.hpp"

int	main( int argc, char **argv) {
	if (argc != 2) {
		std::cout << ERROR_INVALID_ARGUMENTS << std::endl;
		return (FAILURE);
	}
	std::string	level = argv[1];
	Harl	harl;

	harl.complain(level);
	return (SUCCESS);
}