#include "../include/Account.h"
#include "../include/Saving.h"
#include "../include/Utility.h"
#include <iostream>
#include <string>
#include <limits>

using namespace std;

Saving::Saving(int number){
    
    double intrest;
    std::string name;
    double amount;

    flush_input();

    std::cout << "Enter the name of the account holder : ";
    std::getline(std::cin, name);
    std::cout << "Enter the Deposit amount : " ;
    std::cin >> amount;
    cout << "Enter the intrest rate : " << endl;
    cin >> intrest;
 
    this->account_holder = name;
    this->balance = amount;
    this->intrest_rate = intrest;

    this->creation_time_date = get_current_time_date();
    this->account_number = number;
}

int Saving::calculate_intrest(){
    return balance * intrest_rate / 100 ;
}

int Saving::calculate_total_balance(){
    return balance+= calculate_intrest();
}

void Saving::display(){

    std::cout << "The name of the account holder is : " << this->account_holder << std::endl;
    std::cout << "The balance in the account is : " << this->balance << std::endl;
    std::cout << "The Account number is : " << this->account_number << std::endl;
    std::cout << "This account was created on  : " << this->creation_time_date << std::endl ;
    cout << "The intrest on the account is : " << this->intrest_rate;
    calculate_total_balance();
    cout << "The final balance of the account is : " << this->balance;  

}







