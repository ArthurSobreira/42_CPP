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
		std::ifstream	DBFIle("./data.csv");

		if (!DBFIle.is_open() || DBFIle.fail()) {
			throw InvalidFileException();
		}

		std::string	line;
		while (std::getline(DBFIle, line)) {
			std::istringstream	ss(line);
			std::string			date, value;

			if (std::getline(ss, date, ',') && std::getline(ss, value)) {
				if (BTCUtils::dateValid(date)) {
					database[date] = std::strtod(value.c_str(), NULL);
				} else if (date != "date" && value != "exchange_rate") {
					throw InvalidDateException();
				}
			} else {
				throw ParseErrorException();
			}
		}
		DBFIle.close();
	}

	bool	valueValid( std::string value, errorType &error ) {
		double	doubleValue = std::strtod(value.c_str(), NULL);

		if (doubleValue > 1000.0) {
			error = TOO_LARGE_VALUE;
			return (false);
		}
		if (doubleValue < 0) {
			error = NEGATIVE_VALUE;
			return (false);
		}
		return (true);
	}

	void	removeSpaces( std::string &str ) {
		str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
	}
}

/* Constructor Methods */
BitcoinExchange::BitcoinExchange( void ) { throw InvalidFileException(); }

BitcoinExchange::BitcoinExchange( std::string filename ) : _filename(filename) {
	try {
		BTCUtils::parseDatabase(this->_database);
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
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
Database	BitcoinExchange::getDatabase( void ) const {
	return (this->_database);
}

std::string	BitcoinExchange::getFilename( void ) const {
	return (this->_filename);
}

void BitcoinExchange::printExchange( std::string date, std::string value ) const {
	errorType	error;

	if (!BTCUtils::dateValid(date)) {
		throw InvalidDateException();
	}
	if (!BTCUtils::valueValid(value, error)) {
		throw InvalidValueException(error);
	}

	double	doubleValue = std::strtod(value.c_str(), NULL);
	Database	database = this->getDatabase();
	Database::iterator	it = database.upper_bound(date);

	std::cout << date << " => " << doubleValue << " = ";
	if (it == database.begin()) {
		std::cout << it->second * doubleValue << std::endl;
	} else {
		std::cout << std::setprecision(15) << 
		(--it)->second * doubleValue << std::endl;
	}
}

void BitcoinExchange::exchangeRate( void ) const {
	std::ifstream	inputFile(this->getFilename().c_str());

	if (!inputFile.is_open() || inputFile.fail()) {
		throw InvalidFileException();
	}

	std::string	line;
	while (std::getline(inputFile, line)) {
		try {
			BTCUtils::removeSpaces(line);

			if (!line.empty() && !inputFile.eof() && \
				line[line.size() - 2] == '|') {
				throw InvalidValueException(GENERIC_ERROR);
			}

			std::istringstream	ss(line);
			std::string			date, value;

			if (std::getline(ss, date, '|') && std::getline(ss, value)) {
				if (date != "date" && value != "value")
					this->printExchange(date, value);
			} else {
				throw InvalidValueException(GENERIC_ERROR);
			}
		} catch (const std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
}

/* Exception Classes */
const char *InvalidFileException::what( void ) const throw() {
	return (RED "Error: File Could Not Be Opened." RESET);
}

const char *ParseErrorException::what( void ) const throw() {
	return (RED "Error: File Could Not Be Parsed." RESET);
}

const char *InvalidDateException::what( void ) const throw() {
	return (RED "Error: Invalid Date Format." RESET);
}

InvalidValueException::InvalidValueException( errorType error ) 
	: _error(error) {};

const char *InvalidValueException::what( void ) const throw() {
	switch (this->_error) {
		case NEGATIVE_VALUE:
			return (RED "Error: not a positive value." RESET);
		case TOO_LARGE_VALUE:
			return (RED "Error: value too large." RESET);
		default:
			return (RED "Error: bad value format." RESET);
	}
}
