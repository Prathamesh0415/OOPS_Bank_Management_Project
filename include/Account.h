#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

#include <iostream>


class Account {

    private : 
        int account_number {000000};
        double balance;
        std::string account_holder;
        std::string creation_time_date;
    public :
        Account(int acc_no);
        void display();
        int get_account_number();
};

#endif