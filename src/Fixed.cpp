#include "../include/Account.h"
#include "../include/Fixed.h"
#include <iostream>

using namespace std;

Fixed::Fixed(Account *obj){
    this->FD_account_holder = obj->get_account_holder();
    this->FD_account_number = obj->get_account_number();

    cout << "Enter the intrest rate of the Fixed Deposit : " << endl;
    cin >> this->FD_intrest_rate;

    cout << "Enter the deposit amount : " << endl;
    cin >> this->FD_deposit_amount;

    cout << "Enter the time period {in months } : " << endl;
    cin >> this->FD_time_in_months;

}

void Fixed::display(){
    cout << "The account holder of the Fixed Deposit is : " << this->FD_account_holder << endl;
    cout << "The account number of the Fixed deposit is : " << this->FD_account_number << endl;
}

string Fixed::get_FD_account_holder(){
    return this->FD_account_holder;
}

int Fixed::get_FD_account_number(){
    return this->FD_account_number;
}

string Fixed::get_deposit_type(){
    return this->deposit_type;
}

double Fixed::get_FD_intrest_rate(){
    return this->FD_intrest_rate;
}

int Fixed::get_FD_time_in_months(){
    return this->FD_time_in_months;
}

std::string Fixed::get_FD_creation_time_date(){
    return this->FD_creation_time_date;
}
