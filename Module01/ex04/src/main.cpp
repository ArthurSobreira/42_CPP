#include "Defines.hpp"
#include "../includes/Sed.hpp"

int main(int argc, char **argv)
{
	if (argc != 4) {
		std::cout << ERROR_INVALID_ARGUMENTS << std::endl;
		return (1);
	}
	std::string	filename = argv[1];
	std::string	target = argv[2];
	std::string	replacement = argv[3];

	if (target.empty() || replacement.empty()) {
		std::cout << ERROR_NULL_ARGUMENT << std::endl;
		return (1);
	}

	Sed is_for_losers(target, replacement);
	is_for_losers.replace(filename);
	return (0);
}
