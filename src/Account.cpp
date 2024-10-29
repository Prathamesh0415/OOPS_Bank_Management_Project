#include "../include/Account.h"
#include <iostream>
#include <bits/stdc++.h>

Account::Account(std::string name, int amount){
    this->name = name;
    this->balance = amount;
}

void Account::display(){
    std::cout << "The name of the account holder is : " << this->name << std::endl;
    std::cout << "The balance in the account is : " << this->balance << std::endl;
}