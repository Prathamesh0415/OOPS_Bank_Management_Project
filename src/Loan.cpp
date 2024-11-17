#include "../include/Account.h"
#include "../include/Loan.h"
#include "../include/Utility.h"
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

Loan::Loan(Account &obj){
    this->Loan_account_holder = obj.get_account_holder();
    this -> Loan_account_number = obj.get_account_number();
    this->creation = get_current_time_date();

    double l_amount;
    cout<< "Enter the amount to be loaned : "<< endl;
    cin >> l_amount;
    this->loan_amount = l_amount;

    int choice;
    cout << "Enter your choice for loan type:\n Personal Loan \n Home Loan \n Car Loan\n " << endl;
    cin >> choice;
    switch(choice)
    {
    case 1:  //Personal
        this->loan_type = "Personal";
        this->loan_interset = 10.0;
        this->loan_time = 5;
        break;
    case 2:  //Home
        this->loan_type = "Home";
        this->loan_interset = 8.5;
        this->loan_time = 14;
        break;
    case 3: //Car
        this->loan_type = "Car";
        this->loan_interset = 7.5;
        this->loan_time = 7;
        break;
    default:
    cout<< "Inalid Choice. Are you sure you want to proceed?"<<endl;
        break;
    }
    cout << "Loan request has successfully processed " << endl;
    this-> monthly_pay = calculate_monthlypayment();
    this->display();
}

void Loan::display(){
    cout<< "The account holder of the Loan Bearer is : "<<this->Loan_account_holder<<endl;
    cout<< "The account number of the Loan Bearer is : "<<this->Loan_account_number<<endl;
    cout<< "Loan  Amount: "<<this->loan_amount<<endl;
    cout<< "Loan Interest: "<<this->loan_interset<< "%" <<endl;
    cout<< "Loan must be repaid in "<<loan_time<< "years"<<endl;
    cout<< "Monthly Payment: "<<this->monthly_pay<<endl;

}


double Loan::calculate_monthlypayment(){
    int month = loan_time * 12;
    double monthly_rate = (loan_interset/100) / 12;
    if(monthly_rate == 0){
        return (loan_amount / month);
    }
    return loan_amount * (monthly_rate * pow(1 + monthly_rate, month)) / (pow(1 + monthly_rate, month) - 1);

}

double Loan::Total_payment(){
    return monthly_pay * loan_time * 12;
}

string Loan::get_loan_type(){
    return this->loan_type;
}

int Loan::get_account_number(){
    return this->Loan_account_number;
}

double Loan::get_loan_intrest(){
    return this->loan_interset;
}

double Loan::get_loan_amount(){
    return this->loan_amount;
}

double Loan::get_loan_time(){
    return this->loan_time;
}

string Loan::get_creation(){
    return this->creation;
}

string Loan::get_loan_account_holder(){
    return this->Loan_account_holder;
}