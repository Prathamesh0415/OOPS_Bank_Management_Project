#ifndef _RECURRING_H_
#define _RECURRING_H_

#include "Account.h"
#include <iostream>

class Recurring : public Account {
    protected :
        double RD_intrest_rate {0};
        int RD_time_in_months {0};
        double RD_deposit_amount;

    public :
        Recurring(Account &obj);
        void RD_info();
        virtual void deposit();
        virtual void withdraw();
        void maturity_date();
};

#endif