
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
void type_account_display(Bank &obj);
void view_details_account_display(Bank &obj);
void perform_operations_on_accounts(Bank &obj);
void save_account_details(Account &obj, int flag);
void save_RD_details(Recurring &obj, int flag);
void save_FD_details(Fixed &obj);
void update_account_details_in_file(Bank &obj);
void get_a_loan(Bank &obj);
void perform_operations_on_RD(Bank &obj);
void update_RD_details(Bank &obj);
template <typename T>
void delete_element(std::vector<T *>& vec, T &value);
void close_bank_account(Bank &obj);
void transaction_details(Account &obj, int acc_no, std::string transaction_type, double amount);
void save_loan_details(Loan &obj);
template <typename T>
int find_element(std::vector<T *>&vec, int &acc_no);
//void salary_transaction_details(Account &obj, int acc_no);

#endif