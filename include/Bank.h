#ifndef _BANK_H_
#define _BANK_H_

#include <iostream>
#include <vector>
#include <unordered_set>
#include "Account.h"

class Bank {
    public :
        std::vector<Account *> Accounts;
        std::unordered_set<int>account_numbers;
};

#endif