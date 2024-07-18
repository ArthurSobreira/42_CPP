#include "Defines.hpp"
#include "BitcoinExchange.hpp"

/* Utils Namespace */
namespace BTCUtils {
	bool	isLeapYear( int year ) {
		return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	}

	bool	dateValid( std::string date ) {
		if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
			return (false);
		}

		int	year = std::atoi(date.substr(0, 4).c_str());
		int	month = std::atoi(date.substr(5, 2).c_str());
		int	day = std::atoi(date.substr(8, 2).c_str());
		int daysInMonth[] = {
			31, (isLeapYear(year) ? 29 : 28), 31, 
			30, 31, 30, 31, 31, 30, 31, 30, 31
		};

		if (year < 0 || year > 9999 || month < 1 || month > 12) {
			return (false);
		}
		if (day < 1 || day > daysInMonth[month - 1]) {
			return (false);
		}
		return (true);
	}

	void	parseDatabase( std::map<std::string, double> &database ) {
		std::ifstream	dataFile("data.csv");

		if (!dataFile.is_open() || dataFile.fail()) {
			throw BitcoinExchange::InvalidFileException();
		}
		
		std::string	line;
		while (std::getline(dataFile, line)) {
			std::istringstream	ss(line);
			std::string			date, value;

			if (std::getline(ss, date, ',') && std::getline(ss, value)) {
				if (BTCUtils::dateValid(date)) {
					database[date] = std::strtod(value.c_str(), NULL);
				} else if (date != "date" && value != "exchange_rate") {
					throw BitcoinExchange::InvalidDateException();
				}
			} else {
				throw BitcoinExchange::ParseErrorException();
			}
		}
		dataFile.close();
	}
}

/* Constructor Method */
BitcoinExchange::BitcoinExchange( void ) { throw InvalidFileException(); }

BitcoinExchange::BitcoinExchange( std::string filename ) : _filename(filename) {
	try {
		BTCUtils::parseDatabase(this->_database);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
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
