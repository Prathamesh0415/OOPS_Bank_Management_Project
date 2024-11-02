#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

#include <iostream>


class Account {

    protected : 
        int account_number {000000};
        double balance;
        std::string account_holder;
        std::string creation_time_date;
    public :
        Account();
        Account(int acc_no);

        virtual void display();
        virtual void deposit(double amount);
        virtual void withdraw(double amount);

        int get_account_number();
        std::string get_account_holder();
        double get_balance();
};

#endif