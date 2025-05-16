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

using std::string;
using std::endl;
using std::cout;
using std::cin;

void	Account::_displayTimestamp( void )
{
    std::time_t now = std::time(NULL);
    std::tm *ltm = std::localtime(&now);
}

Account::Account(void)
{
}

Account::~Account()
{
}

