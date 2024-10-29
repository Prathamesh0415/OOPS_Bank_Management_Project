#include <iostream>
#include <bits/stdc++.h>
#include "./include/Account.h"
//#include "C:\Skills\College\C++_OOPS\Project_Bank_Management\utils\Account_opeation.cpp"

using namespace std;

int main(){
    int choice {0};
    
    while(1){
        
        cout << "Refer the catlaoug given below to perform the required task : " << endl;
        cout << " 1. Create new Account " << endl;
        cout << " 2. View account details " << endl;
        cout << " 3. Update existing account " << endl;
        cout << " 4. Exit " << endl;
        
        cin >> choice;

        if (choice == 4) {
            cout << "Thank you for trying us " << endl;
            break;
        }

        Account a2{"admin", 000};

        switch (choice) {
            case 1:{
                cout << "Adding functionality to create account" << endl;
                Account a1{"prat", 123};
                break;
            }
            case 2:{
                cout << "Adding functionality to view existing account " << endl;
                a2.display();
                //create_account();
                break;
            }
            case 3:{
                cout << "Adding functionality to update existing account " << endl;
                break;
            }
            default :
                cout << "Please select appropiate option " << endl;
                break;
        }

    }
    
}