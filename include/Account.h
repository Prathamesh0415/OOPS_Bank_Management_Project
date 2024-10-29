#ifndef _ACCOUNT_H_
#define _ACOUNT_H_

#include <iostream>

class Account{
    private : 
        std::string name;
        int balance;
    public :
        Account(std::string name, int amount);
        void display();
};

#endif