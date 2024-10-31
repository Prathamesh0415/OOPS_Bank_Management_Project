#ifndef ACCOUNT_H_
#define ACCOUNT_H_

#include <iostream>
#include "Bank.h"

class Account {
    private : 
        int account_number;
        double balance;
        std::string account_holder;
        std::string creation_time_date;
    public :
        Account(std::string name, double amount, std::string time);
        void display();
};

#endif