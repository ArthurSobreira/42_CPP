#include <iostream>
#include <string>

int	main(int argC, char *argV[])
{
	if (argC == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; i < argC; i++)
	{
		std::string str = argV[i];
		for (size_t j = 0; j < str.length(); j++)
			std::cout << (char)std::toupper(str[j]);
	}
	std::cout << std::endl;
	return (0);
}

