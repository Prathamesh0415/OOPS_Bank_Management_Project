#include "../include/Account.h"
#include <iostream>
#include <bits/stdc++.h>

Account::Account(std::string name, double amount, std::string time){
    this->account_holder = name;
    this->balance = amount;
    this->creation_time_date = time
}

void Account::display(){
    std::cout << "The name of the account holder is : " << this->account_holder << std::endl;
    std::cout << "The balance in the account is : " << this->balance << std::endl;
}