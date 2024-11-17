#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

#include <iostream>

class Account {

    friend std::ostream &operator<<(std::ostream &out, Account &obj);

    protected : 
        std::string account_type {"Bank Account"};
        int account_number {000000};
        double balance;
        std::string account_holder;
        std::string creation_time_date;

    public :

    static int deposit_counter;
    static int withdraw_counter;
    static int sr_no;

        Account();
        Account(int acc_no, std::string name, double amount);

        virtual void display();
        virtual void deposit(double amount);
        virtual void withdraw(double amount);

        virtual int get_account_number();
        std::string get_account_holder();
        std::string get_creation_time_date();
        double get_balance();
        std::string get_account_type();

        bool operator==( Account &obj);

        virtual void deposit_salary();
       // virtual double get_salary();

};

#endif