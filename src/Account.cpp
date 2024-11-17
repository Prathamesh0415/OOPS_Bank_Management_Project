#include "../include/Account.h"
#include "../include/Utility.h"
#include <iostream>
#include <string>
#include <limits>

using namespace  std;

Account::Account(){};

Account::Account(int number, string name, double amount){

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

string Account::get_account_holder(){
    return this->account_holder;
}

double Account::get_balance(){
    return this->balance;
}

void Account::deposit(double amount){
    this->balance += amount;
}

void Account::withdraw(double amount){
    this->balance -= amount;
}

string Account::get_creation_time_date(){
    return this->creation_time_date;
}

string Account::get_account_type(){
    return this->account_type;
}

ostream& operator<<(ostream &out, Account &obj){

    int acc_no = obj.get_account_number() % 1000;

    out << "The name of the account holder is : " << endl;
    out << obj.get_account_holder() << endl;
    out << "The account number of the account holder is : " << endl;
    out << "XXXX" << acc_no << endl;
    out << "The balance of the account is : " << endl;
    out << obj.get_balance() << endl;

    return out;

}

bool Account::operator==(Account &obj){
    return this->get_account_number() == obj.get_account_number();
}