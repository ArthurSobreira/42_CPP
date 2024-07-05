#include "Defines.hpp"
#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>
#include <limits>
#include <cmath>

/* Constructor Method */
ScalarConverter::ScalarConverter( void ) {};

/* Copy Constructor Method */
ScalarConverter::ScalarConverter( const ScalarConverter &other ) {
	*this = other;
}

/* Copy Assignment Operator Overload */
ScalarConverter &ScalarConverter::operator=( const ScalarConverter &other ) {
	(void)other;
	return (*this);
}

/* Destructor Method */
ScalarConverter::~ScalarConverter( void ) {};

/* Public Methods */
namespace ConversionFunctions {
	bool	isPseudoLiteral( std::string const &value ) {
		if (value == "-inff" || value == "+inff" || value == "nanf" || \
			value == "-inf" || value == "+inf" || value == "nan" || \
			value == "inf" || value == "inff") {
			return (true);
		}
		return (false);
	}

	bool	isnumber( std::string const &value ) {
		for (size_t i = 0; i < value.size(); ++i) {
			if (!std::isdigit(value[i]) && value[i] != '.' && value[i] != 'f' && \
				value[i] != '+' && value[i] != '-') {
				return (false);
			}
		}
		return (true);
	}

	std::string	handleDecimal( std::string const &value, bool isFloat ) {
		std::string result = "";
		size_t	dotPos = value.find('.');
		size_t	lastPosition = value.size() - 1;

		if (!isPseudoLiteral(value)) {
			if (dotPos == std::string::npos || \
				(dotPos == value.size() - 2 && value[lastPosition] == '0') || \
				(isFloat && dotPos == value.size() - 3 && \
				value[lastPosition] == 'f' && value[value[lastPosition] - 1] == '0')) {
				result = ".0";
			} else if (dotPos != std::string::npos) {
				bool zerosAfterDot = true;

				for (size_t i = dotPos + 1; i < value.size(); ++i) {
					if (value[i] != '0' && value[i] != 'f') {
						zerosAfterDot = false;
						break;
					}
				}
				if (zerosAfterDot) {
					result = ".0";
				}
			}
		}
		if (isFloat) {
			result += 'f';
		}
		return (result);
	}

	char	toChar( std::string const &value ) {
		if (ConversionFunctions::isPseudoLiteral(value) || \
			!ConversionFunctions::isnumber(value)) {
			throw ScalarConverter::ImpossibleException();
		}

		double cValue = std::strtod(value.c_str(), NULL);
		if (cValue < std::numeric_limits<char>::min() || \
			cValue > std::numeric_limits<char>::max() || \
			std::isnan(cValue)) {
			throw ScalarConverter::ImpossibleException();
		} else if (!std::isprint(static_cast<char>(cValue))) {
			throw ScalarConverter::NonDisplayableException();
		}
		return (static_cast<char>(cValue));
	}

	int		toInt( std::string const &value ) {
		if (ConversionFunctions::isPseudoLiteral(value) || \
			!ConversionFunctions::isnumber(value)) {
			throw ScalarConverter::ImpossibleException();
		}

		double iValue = std::strtod(value.c_str(), NULL);
		if (iValue < std::numeric_limits<int>::min() || \
			iValue > std::numeric_limits<int>::max() || \
			std::isnan(iValue)) {
			throw ScalarConverter::ImpossibleException();
		}
		return (static_cast<int>(iValue));
	}

	float	toFloat( std::string const &value ) {
		if (!ConversionFunctions::isPseudoLiteral(value) && \
			!ConversionFunctions::isnumber(value)) {
			throw ScalarConverter::ImpossibleException();
		}
		
		if (value == "nanf") {
			return std::numeric_limits<float>::quiet_NaN();
		}
		if (value == "+inff") {
			return std::numeric_limits<float>::infinity();
		}
		if (value == "-inff") {
			return -std::numeric_limits<float>::infinity();
		}

		float fValue = std::strtof(value.c_str(), NULL);
		return (static_cast<float>(fValue));
	}

	float	toDouble( std::string const &value ) {
		if (!ConversionFunctions::isPseudoLiteral(value) && \
			!ConversionFunctions::isnumber(value)) {
			throw ScalarConverter::ImpossibleException();
		}

		if (value == "nan" || value == "nanf") {
			return std::numeric_limits<double>::quiet_NaN();
		}
		if (value == "+inf" || value == "+inff") {
			return std::numeric_limits<double>::infinity();
		}
		if (value == "-inf" || value == "-inff") {
			return -std::numeric_limits<double>::infinity();
		}

		double dValue = std::strtod(value.c_str(), NULL);
		return (static_cast<float>(dValue));
	}
}

void	ScalarConverter::convert( std::string const &value ) {
	try {
		const char cValue = ConversionFunctions::toChar(value);

		std::cout << COLORIZE(BOLD_BLUE, "char: '") << cValue << 
		COLORIZE(BOLD_BLUE, "'") << std::endl;
	} catch (const std::exception &e) {
		std::cout << COLORIZE(BOLD_BLUE, "char: ") << e.what() << std::endl;
	}
	try {
		const int iValue = ConversionFunctions::toInt(value);

		std::cout << COLORIZE(BOLD_BLUE, "int: '") << iValue << 
		COLORIZE(BOLD_BLUE, "'") << std::endl;
	} catch (const std::exception &e) {
		std::cout << COLORIZE(BOLD_BLUE, "int: ") << e.what() << std::endl;
	}
	try {
		const float	fValue = ConversionFunctions::toFloat(value);

		std::cout << COLORIZE(BOLD_BLUE, "float: '") << fValue <<
		ConversionFunctions::handleDecimal(value, true) << 
		COLORIZE(BOLD_BLUE, "'") << std::endl;
	} catch (const std::exception &e) {
		std::cout << COLORIZE(BOLD_BLUE, "float: ") << e.what() << std::endl;
	}
	try {
		const double dValue = ConversionFunctions::toDouble(value);

		std::cout << COLORIZE(BOLD_BLUE, "double: '") << dValue << 
		ConversionFunctions::handleDecimal(value, false) <<
		COLORIZE(BOLD_BLUE, "'") << std::endl;
	} catch (const std::exception &e) {
		std::cout << COLORIZE(BOLD_BLUE, "double: ") << e.what() << std::endl;
	}
}

/* Exception Classes */
const char *ScalarConverter::NonDisplayableException::what() const throw() {
	return ("Non displayable");
}

const char *ScalarConverter::ImpossibleException::what() const throw() {
	return ("impossible");
}
