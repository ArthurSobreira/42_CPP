#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <cstring>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void ) {
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount( void ) {
	return (Account::_totalAmount);
}

int	Account::getNbDeposits( void ) {
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void ) {
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void ) {
	Account::_displayTimestamp();
	std::cout << "accounts:" << \
	Account::getNbAccounts() << ";total:" << \
	Account::getTotalAmount() << ";deposits:" << \
	Account::getNbDeposits() << ";withdrawals:" << \
	Account::getNbWithdrawals() << std::endl;
}

Account::Account( int initial_deposit ) : _accountIndex(Account::getNbAccounts()), \
	_amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << \
				";amount:" << this->checkAmount() << ";created" << std::endl;
	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;
}

Account::~Account( void ) {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << \
				";amount:" << this->checkAmount() << ";closed" << std::endl;
	Account::_nbAccounts--;
	Account::_totalAmount -= this->checkAmount();
}

void Account::makeDeposit( int deposit ) {
	int		oldAmount = this->_amount;

	Account::_displayTimestamp();
	if (deposit <= 0) {
		std::cout << "index:" << this->_accountIndex << ";p_amount:" \
		<< this->_amount << ";deposit:refused" << std::endl;
		return ;
	}

	this->_amount += deposit;
	Account::_totalAmount += deposit;
	this->_nbDeposits++;
	Account::_totalNbDeposits++;
	std::cout << "index:" << this->_accountIndex << ";p_amount:" \
	<< oldAmount << ";deposit:" << deposit << ";amount:" \
	<< this->_amount << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ) {
	int		oldAmount = this->_amount;

	Account::_displayTimestamp();
	if (withdrawal <= 0 || this->_amount - withdrawal < 0) {
		std::cout << "index:" << this->_accountIndex << ";p_amount:" \
		<< this->_amount << ";withdrawal:refused" << std::endl;
		return (false);
	}

	this->_amount -= withdrawal;
	Account::_totalAmount -= withdrawal;
	this->_nbWithdrawals++;
	Account::_totalNbWithdrawals++;
	std::cout << "index:" << this->_accountIndex << ";" << "p_amount:" \
	<< oldAmount << ";" << "withdrawal:" << withdrawal << ";" \
	<< "amount:" << this->_amount << ";" << "nb_withdrawals:" \
	<< this->_nbWithdrawals << std::endl;
	return (true);
}

int	Account::checkAmount( void ) const {
	return (this->_amount);
}

void	Account::displayStatus( void ) const {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" \
	<< this->checkAmount() << ";deposits:" << this->_nbDeposits \
	<< ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp( void ) {
	char		timestamp[18];
	time_t		rawtime;
	struct tm	*timeinfo;

	time(&rawtime);
	timeinfo = localtime(&rawtime);
	strftime(timestamp, 19, "[%Y%m%d_%H%M%S] ", timeinfo);
	std::cout << timestamp << std::flush;
	memset(timestamp, 0, 18);
}

Account::Account( void ) : _accountIndex(Account::getNbAccounts()), \
	_amount(0), _nbDeposits(0), _nbWithdrawals(0) {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << \
				";amount:" << this->checkAmount() << \
				";created" << std::endl;
	Account::_nbAccounts++;
}
