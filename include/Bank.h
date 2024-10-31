#ifndef BANK_H_
#define BANK_H_

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include "Account.h"

class Bank{
    private :
        std::vector<int>Accounts;
        std::unordered_set<int> account_numbers;
        int generate_random_acc_number();
    public :
        Account* create_account(std::string name, double amount);
        void list_Account();
};

#endif