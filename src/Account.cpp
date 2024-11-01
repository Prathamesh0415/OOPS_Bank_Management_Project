#include "../include/Account.h"
#include "../include/Utility.h"
#include <iostream>


Account::Account(){

    std::string name;
    double amount;

    std::cout << "Enter the name of the account holder : " << std::endl;
    std::cin >> name;
    std::cout << "Enter the Deposit amount : " << std:: endl;
    std::cin >> amount;
 
    this->account_holder = name;
    this->balance = amount;
    
    this->creation_time_date = get_current_time_date();
    this->account_number = random_generation_acc_number();


}

void Account::display(){

    std::cout << "The name of the account holder is : " << this->account_holder << std::endl;
    std::cout << "The balance in the account is : " << this->balance << std::endl;
    std::cout << "The Account number is : " << this->account_number << std::endl;
    std::cout << "This account was created on  : " << this->creation_time_date << std::endl ; 
}