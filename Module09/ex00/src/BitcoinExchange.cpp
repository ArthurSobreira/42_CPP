#include "Defines.hpp"
#include "BitcoinExchange.hpp"

namespace BTCUtils {
	bool	isLeapYear( int year ) {
		(year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	}

	bool	dateValid( std::string date ) {
		if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
			return (false);
		}

		int	year = std::stoi(date.substr(0, 4));
		int	month = std::stoi(date.substr(5, 2));
		int	day = std::stoi(date.substr(8, 2));
		int daysInMonth[] = {
			31, 0, 31, 30, 31, 30, 
			31, 31, 30, 31, 30, 31
		};
		daysInMonth[1] = isLeapYear(year) ? 29 : 28;

		if (year < 0 || year > 9999 || month < 1 || month > 12) {
			return (false);
		}
		if (day < 1 || day > daysInMonth[month - 1]) {
			return (false);
		}
		return (true);
	}
}

/* Constructor Method */
BitcoinExchange::BitcoinExchange( void ) { throw InvalidFileException(); }

BitcoinExchange::BitcoinExchange( std::string filename ) : _filename(filename) {
	std::ifstream	dataFile("data.csv");

	if (!dataFile.is_open() || dataFile.fail()) {
		throw InvalidFileException();
	}
	
	std::string	line;
	while (std::getline(dataFile, line)) {
		std::istringstream	ss(line);
		std::string			date;
		double				value;

		if (std::getline(ss, date, ',') && std::getline(ss, value)) {
			if (dateValid(date)) {
				this->getDatabase()[date] = std::stod(value);
			}
		} else {
			throw ParseErrorException();
		}
	}
	dataFile.close();
}
/* Copy Constructor Method */
BitcoinExchange::BitcoinExchange( const BitcoinExchange &other ) {
	*this = other;
}

/* Copy Assignment Operator Overload */
BitcoinExchange &BitcoinExchange::operator=( const BitcoinExchange &other ) {
	if ( this != &other ) {
		this->_database = other.getDatabase();
		this->_filename = other.getFilename();
	}
	return (*this);
}

/* Destructor Method */
BitcoinExchange::~BitcoinExchange( void ) {};

/* Public Methods */
std::map<std::string, double> BitcoinExchange::getDatabase( void ) const {
	return (this->_database);
}

std::string BitcoinExchange::getFilename( void ) const {
	return (this->_filename);
}

/* Exception Classes */
const char *BitcoinExchange::InvalidFileException::what( void ) const throw() {
	return (RED "Error: File Could Not Be Opened." RESET);
}

const char *BitcoinExchange::ParseErrorException::what( void ) const throw() {
	return (RED "Error: File Could Not Be Parsed." RESET);
}

const char *BitcoinExchange::InvalidDateException::what( void ) const throw() {
	return (RED "Error: Invalid Date Format." RESET);
}
