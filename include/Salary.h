#ifndef _SALARY_H_
#define _SALARY_H_

#include "Account.h"
#include <iostream>

class Salary : public Account {
private:
    double monthly_salary;

public:
    static int sr_no;
    Salary();
    Salary(int acc_no, double salary, std::string name);

    void display() override;
    void deposit(double amount) override;
    void withdraw(double amount) override;

    void set_salary(double salary);
    double get_salary() const;

    virtual int get_account_number();
    virtual void deposit_salary();
};

#endif