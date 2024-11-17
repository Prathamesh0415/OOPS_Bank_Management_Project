#ifndef LOAN_H
#define LOAN_H
#include <iostream>
#include "Account.h"

class Loan : public Account{
    protected: 
        std::string loan_type; 
        std::string Loan_account_holder;
        int Loan_account_number;
        int loan_time;
        double loan_interset{0};
        double loan_amount{0};
        double monthly_pay{0};
        std::string creation; 

    public:
    Loan();
    Loan(Account &obj);
    double calculate_monthlypayment();
    double Total_payment();
    virtual void display();

    std::string get_loan_type();
    std::string get_loan_account_holder();
    int get_account_number();
    double get_loan_intrest();
    double get_loan_time();
    double get_loan_amount();
    std::string get_creation();
    //std::string get_loan_holder();

    

};


#endif