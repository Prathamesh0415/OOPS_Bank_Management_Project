#ifndef _FIXED_H_
#define _FIXED_H_

#include <iostream>
#include "Account.h"

class Fixed : public Account {
    protected :
        std::string FD_account_holder;
        int FD_account_number;
        double FD_intrest_rate {0};
        double FD_deposit_amount {0};
        int FD_time_in_months {0};

    public :
        Fixed(Account *obj);
        //void FD_info();
        //virtual void withdraw();
        //void maturity_date();
        virtual void display();
};   

#endif