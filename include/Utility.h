
#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>
#include "Bank.h"
#include "Account.h"
#include "Recurring.h"
#include "Fixed.h"

std::string get_current_time_date();
int random_generation_acc_number();
void flush_input();
void main_display();
Account type_account_display(Bank &obj);
void view_details_account_display(Bank &obj);
void perform_operations_on_accounts(Bank &obj);
void save_account_details(Account &obj, int flag);
void save_RD_details(Recurring &obj);
void save_FD_details(Fixed &obj);
void update_account_details_in_file(Bank &obj);

#endif