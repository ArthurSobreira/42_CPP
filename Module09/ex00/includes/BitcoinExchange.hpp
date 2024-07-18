#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <iomanip>
#include <map>

class BitcoinExchange {
	private:
		std::map<std::string, double>	_database;
		std::string	_filename;
		
	public:
		/* Constructor Method */
		BitcoinExchange( void );
		BitcoinExchange( std::string filename );
		
		/* Copy Constructor Method */
		BitcoinExchange( const BitcoinExchange &other );
		
		/* Copy Assignment Operator Overload */
		BitcoinExchange &operator=( const BitcoinExchange &other );
		
		/* Destructor Method */
		~BitcoinExchange( void );
		
		/* Public Methods */
		std::map<std::string, double>	getDatabase( void ) const;
		std::string						getFilename( void ) const;

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
};

#endif
