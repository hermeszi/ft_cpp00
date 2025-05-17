#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <ctime>
using std::string;
using std::endl;
using std::cout;
using std::cin;

#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

//========================PUBLIC=========================
//START STATIC
int		Account::getNbAccounts( void )
{
	return (_nbAccounts);
}
int		Account::getTotalAmount( void )
{
	return (_totalAmount);
}
int		Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}
int		Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}
void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	cout	<< " "
			<< "accounts:"		<< _nbAccounts			<< ";"
			<< "total:"			<< _totalAmount			<< ";"
			<< "deposits:"		<< _totalNbDeposits		<< ";"
			<< "withdrawals:"	<< _totalNbWithdrawals
			<< endl;
}
//END STATIC

Account::Account(int initial_deposit) : _accountIndex(_nbAccounts),
										_amount(initial_deposit),
										_nbDeposits(0),
										_nbWithdrawals(0)
{
	_nbAccounts++;
	_totalAmount += initial_deposit;

	_displayTimestamp();
	std::cout << " index:" << _accountIndex
	          << ";amount:" << _amount
	          << ";created" << std::endl;
}
Account::~Account(void)
{
	_displayTimestamp();
	cout	<< " "
			<< "index:"	<< _accountIndex	<< ";"
	    	<< "amount:"	<< _amount			<< ";"
	    	<< "closed"
			<< endl;
}

void	Account::displayStatus(void) const
{
    _displayTimestamp();
    cout	<< " "
			<< "index:"	<< _accountIndex	<< ";"
        	<< "amount:" << _amount			<< ";"
            << "deposits:" << _nbDeposits	<< ";"
            << "withdrawals:" << _nbWithdrawals
            << endl;
}
void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	cout	<< " "
			<< "index:"		<< _accountIndex	<< ";"
	       	<< "p_amount:"	<< _amount			<< ";"
	       	<< "deposit:"	<< deposit			<< ";";

	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;

	cout	<< "amount:"		<< _amount		<< ";"
	       	<< "nb_deposits:"	<< _nbDeposits
	       	<< endl;
}
bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	cout	<< " "
			<< "index:" 	<< _accountIndex	<< ";"
	        << "p_amount:"	<< _amount			<< ";"
			<< "withdrawal:";
	        

	if (_amount < withdrawal)
	{
		cout << "refused" << endl;
		return false;
	}

	_amount -= withdrawal;
	_nbWithdrawals++;

	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;

	cout	<< withdrawal		<< ";"
	        << "amount:"			<< _amount			<< ";"
	        << "nb_withdrawals:"	<< _nbWithdrawals
	        << endl;

	return true;
}
int		Account::checkAmount(void) const
{
	return (_amount);
}

//========================PRIVATE========================
void	Account::_displayTimestamp( void )
{
	std::time_t			c_time = std::time(NULL);
	std::tm				*l_time = std::localtime(&c_time);

	cout	<< "["
			<< (l_time->tm_year + 1900)
			<< (l_time->tm_mon + 1 < 10 ? "0" : "")	<< (l_time->tm_mon + 1)
			<< (l_time->tm_mday < 10 ? "0" : "")	<< (l_time->tm_mday)
			<< "_"
			<< (l_time->tm_hour < 10 ? "0" : "")	<< (l_time->tm_hour)
			<< (l_time->tm_min < 10 ? "0" : "") 	<< (l_time->tm_min)
			<< (l_time->tm_sec < 10 ? "0" : "")		<< (l_time->tm_sec)
			<< "]";
}
Account::Account(void)
{
	//empty
}

//diff <(cut -c18- 19920104_091532.log) <(cut -c18- test.log)
