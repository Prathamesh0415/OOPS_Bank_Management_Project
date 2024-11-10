
#include "../include/Account.h"
#include "../include/Salary.h"
#include <iostream>

using namespace std;

Salary::Salary() : Account(), monthly_salary(0.0) {}

Salary::Salary(int acc_no, double salary, string name) : Account(acc_no, name, salary), monthly_salary(salary) {
    this->account_type = "Salary Account";
}

void Salary::display() {
    Account::display(); 
    cout << "Monthly Salary is : " << this->monthly_salary << endl;
}

void Salary::deposit(double amount) {
    this->balance += amount;
    cout << "Deposited " << amount << " to salary account. New balance: " << this->balance << endl;
}

void Salary::withdraw(double amount) {
    if (amount <= this->balance) {
        this->balance -= amount;
        cout << "Withdrew " << amount << " from salary account. New balance: " << this->balance << endl;
    } else {
        cout << "Insufficient balance to withdraw " << amount << endl;
    }
}

void Salary::set_salary(double salary) {
    this->monthly_salary = salary;
    this->balance = salary;  
}

double Salary::get_salary() const {
    return this->monthly_salary;
}
