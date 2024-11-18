#ifndef _ERRORS_H_
#define _ERRORS_H_

#include <iostream>
#include "Account.h"

int get_input_number();
double get_deposit_amount(int flag);
double get_intrest_rate();
double get_withdraw_amount(Account &obj);
//int get_account_number(Bank &obj);

#endif