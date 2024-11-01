#include "../include/Account.h"
#include "../include/Utility.h"
#include <iostream>
#include <string>
#include <limits>

using namespace  std;

Account::Account(int number){

    std::string name;
    double amount;

    flush_input();

    std::cout << "Enter the name of the account holder : ";
    std::getline(std::cin, name);
    std::cout << "Enter the Deposit amount : " ;
    std::cin >> amount;
 
    this->account_holder = name;
    this->balance = amount;

    this->creation_time_date = get_current_time_date();
    this->account_number = number;

}

void Account::display(){

    std::cout << "The name of the account holder is : " << this->account_holder << std::endl;
    std::cout << "The balance in the account is : " << this->balance << std::endl;
    std::cout << "The Account number is : " << this->account_number << std::endl;
    std::cout << "This account was created on  : " << this->creation_time_date << std::endl ; 
}

int Account::get_account_number(){
    return this->account_number;
}