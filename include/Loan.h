#ifndef LOAN_H
#define LOAN_H
#include <iostream>
#include "Account.h"

class Loan : public Account{
    protected: 
        std::string Loan_account_holder;
        int Loan_account_number;
        int loan_time;
        double loan_interset{0};
        double loan_amount{0};
        double monthly_pay{0};

    public:
    Loan();
    Loan(Account &obj);
    double calculate_monthlypayment();
    double Total_payment();
    virtual void display();

};


#endif