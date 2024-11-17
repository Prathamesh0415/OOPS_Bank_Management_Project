#include "../include/Recurring.h"
#include "../include/Account.h"
#include "../include/Utility.h"
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

    this->RD_deposit = amount;
    this->RD_creation_time_date = get_current_time_date();
    this->RD_maturity_amount = get_maturity_amount();
}

double Recurring::get_maturity_amount(){
    return (this->RD_deposit_amount * this->RD_time_in_months)
            + (this->RD_deposit_amount * this->RD_time_in_months) * (this->RD_intrest_rate);
}


void Recurring::display(){
    cout << "The account holder of the Recurring Deposit is : " << this->RD_account_holder << endl;
    cout << "The account number of the Recurring deposit is : " << this->RD_account_number << endl;
    cout << "The maturity time of the RD is : " << this->RD_time_in_months << endl;
    cout << "The amount to be deposited monthly is : " << this->RD_deposit_amount << endl; 
    cout << "The amount gained after the maturity of the Recurring Deposit is : " << this->RD_maturity_amount << endl;
}

string Recurring::get_RD_account_holder(){
    return this->RD_account_holder;
}

int Recurring::get_account_number(){
    return this->RD_account_number;
}

string Recurring::get_deposit_type(){
    return this->deposit_type;
}

double Recurring::get_RD_intrest_rate(){
    return this->RD_intrest_rate;
}

int Recurring::get_RD_time_in_months(){
    return this->RD_time_in_months;
}

std::string Recurring::get_RD_creation_time_date(){
    return this->RD_creation_time_date;
}

void Recurring::deposit(){
    this->RD_deposit += RD_deposit_amount;
}
