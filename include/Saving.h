#ifndef _SAVING_H_
#define _SAVING_H_

#include "Account.h"
#include <iostream>

class Saving: public Account {
    protected :
        double intrest_rate {0};
    public :
        //static int sr_no ;
        Saving(int number, std::string name, double interst, double amount);
        virtual void display() override;
        int calculate_intrest();
        int calculate_total_balance();

        virtual int get_account_number();
};

#endif