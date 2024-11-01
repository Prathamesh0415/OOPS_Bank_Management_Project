#include "../include/Account.h"
#include <iostream>
#include <bits/stdc++.h>
#include <ctime>

Account::Account(){

    std::string name;
    double amount;

    std::cout << "Enter the name of the account holder : " << std::endl;
    std::cin >> name;
    std::cout << "Enter the Deposit amount : " << std:: endl;
    std::cin >> amount;



    std::time_t current_time = std::time(nullptr);
    std::string date_time = std::ctime(&current_time);

    this->account_holder = name;
    this->balance = amount;
    //this->creation_time_date =  date_time;

    
}

void Account::display(){
    std::cout << "The name of the account holder is : " << this->account_holder << std::endl;
    std::cout << "The balance in the account is : " << this->balance << std::endl;
}