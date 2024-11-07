#include "../include/Recurring.h"
#include "../include/Account.h"
#include <iostream>

using namespace std;

Recurring::Recurring(Account *obj){
    this->RD_account_holder = obj->get_account_holder();
    this->RD_account_number = obj->get_account_number();

    double intrest;
    cout << "Enter the intrest rate of the Recurring deposit : " << endl;
    cin >> intrest;
    this->RD_intrest_rate = intrest;

    int time;
    cout << "Enter the time period {in Months} : " << endl;
    cin >> time;
    this->RD_time_in_months = time;

    double amount;
    cout << "Enter the amount to be deposited monthly : " << endl;
    cin >> amount;
    this->RD_deposit_amount = amount;
}

void Recurring::display(){
    cout << "The account holder of the Recurring Deposit is : " << this->RD_account_holder << endl;
    cout << "The account number of the Recurring deposit is : " << this->RD_account_number << endl;
}




