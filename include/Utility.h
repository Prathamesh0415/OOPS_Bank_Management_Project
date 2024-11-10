
#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>
#include "Bank.h"
#include "Account.h"

std::string get_current_time_date();
int random_generation_acc_number();
void flush_input();
void main_display();
Account type_account_display(Bank &obj);
void view_details_account_display(Bank &obj);
void perform_operations_on_accounts(Bank &obj);
void save_account_details(Account &obj);

#endif