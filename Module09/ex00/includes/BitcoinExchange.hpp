#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include "Defines.hpp"
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <iomanip>
#include <map>

typedef enum errors {
	GENERIC_ERROR = 1,
	NEGATIVE_VALUE,
	TOO_LARGE_VALUE,
} errorType;

typedef	std::map<std::string, double>	Database;

class BitcoinExchange {
	private:
		Database	_database;
		std::string	_filename;
		
	public:
		/* Constructor Methods */
		BitcoinExchange( void );
		BitcoinExchange( std::string filename );
		
		/* Copy Constructor Method */
		BitcoinExchange( const BitcoinExchange &other );
		
		/* Copy Assignment Operator Overload */
		BitcoinExchange &operator=( const BitcoinExchange &other );
		
		/* Destructor Method */
		~BitcoinExchange( void );
		
		/* Public Methods */
		Database		getDatabase( void ) const;
		std::string		getFilename( void ) const;
		void	printExchange( std::string date, 
			std::string value ) const;
		void	exchangeRate( void ) const;
};

/* Exception Classes */
class InvalidFileException : public std::exception {
	public:
		virtual const char *what( void ) const throw();
};

class ParseErrorException : public std::exception {
	public:
		virtual const char *what( void ) const throw();
};

class InvalidDateException : public std::exception {
	public:
		virtual const char *what( void ) const throw();
};

class InvalidValueException : public std::exception {
	private:
		errorType	_error;

	public:
		InvalidValueException( errorType error ) : _error(error) {};

		virtual const char *what( void ) const throw();
};

#endif
