#include "../include/Account.h"
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

Account create_account(){
    string name;
    int balance;

    cout << "Enter the name of the account holder : " << endl;
    cin >> name;
    cout << "Enter the starting balance : " << endl;
    cin >> balance;
    
    Account temp{name, balance};
    return temp;
}