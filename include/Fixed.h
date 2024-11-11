#ifndef _FIXED_H_
#define _FIXED_H_

#include <iostream>
#include "Account.h"

class Fixed : public Account {
    protected :
        std::string deposit_type {"Fixed Deposit"};
        std::string FD_account_holder;
        int FD_account_number;
        double FD_intrest_rate {0};
        double FD_deposit_amount {0};
        int FD_time_in_months {0};
        std::string FD_creation_time_date;

    public :
        Fixed(Account *obj);
        std::string get_FD_account_holder();
        int get_FD_account_number();
        std::string get_deposit_type();
        double get_FD_intrest_rate();
        int get_FD_time_in_months();
        std::string get_FD_creation_time_date();
        //void FD_info();
        //virtual void withdraw();
        //void maturity_date();
        virtual void display();
};   

#endif