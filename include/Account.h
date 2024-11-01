#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

#include <iostream>


class Account {
    private : 
        //int account_number;
        double balance;
        std::string account_holder;
        //std::string creation_time_date;
    public :
        Account();
        void display();
};

#endif