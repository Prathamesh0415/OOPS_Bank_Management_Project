#ifndef _BANK_H_
#define _BANK_H_

#include <iostream>
#include <vector>
#include <unordered_set>
#include "Account.h"
#include "Recurring.h"
#include "Fixed.h"
#include "Loan.h"

class Bank {
    public :
        std::vector<Account *> Accounts;
        std::unordered_set<int>account_numbers;
        std::vector<Recurring *>Recurring_deposits;
        std::vector<Fixed *>Fixed_deposits;
        std::vector<Loan *>Loan;
};

#endif