#ifndef _RECURRING_H_
#define _RECURRING_H_

#include "Account.h"
#include <iostream>

class Recurring : public Account {
    protected :
        double RD_deposit {0};
        double RD_maturity_amount;
        std::string deposit_type {"Reccurring Deposit"};
        int RD_account_number {0};
        std::string RD_account_holder ; 
        double RD_intrest_rate {0};
        int RD_time_in_months {0};
        double RD_deposit_amount;
        std::string RD_creation_time_date; 


    public :
        Recurring(Account *obj);
        std::string get_RD_account_holder();
        //int get_RD_account_number();
        std::string get_deposit_type();
        double get_RD_intrest_rate();
        int get_RD_time_in_months();
        std::string get_RD_creation_time_date();
        double get_maturity_amount();
        //void RD_info();
        virtual void deposit();
        virtual int get_account_number() override;
        //virtual void withdraw();
        //void maturity_date();
        virtual void display();
};

#endif