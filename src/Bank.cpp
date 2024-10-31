#include "../include/Bank.h"
#include <iostream>
#include <bits/stdc++.h>
#include <ctime>

int Bank::generate_random_acc_number(){
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    int account_number {0} ;
    do {
        account_number = 100000 + std::rand() % 900000;
    } while (account_numbers.find(account_number) != account_numbers.end());

    return account_number;
}

Account* Bank::create_account(std::string name, double amount){
    std::time_t current_time = std::time(nullptr);
    std::string date_time = std::ctime(&current_time);
    int acc_number = generate_random_acc_number();

    Account* account = new Account(name, amount, date_time);
    Bank::Accounts.push_back(account);
    return account;

}