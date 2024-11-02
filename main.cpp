#include <iostream>
#include <vector>
#include <unordered_set>
#include "./include/Account.h"
#include "./include/Bank.h"
#include "./include/Utility.h"
#include "./include/Saving.h"

using namespace std;

int main(){
    int choice {0};

    Bank Bank;
    
    while(1){
        
        display();
        
        cin >> choice;

        if (choice == 4) {
            cout << "Thank you for trying us " << endl;
            break;
        }
        switch (choice) {
            case 1:{
                int acc_no = {000000};
                do{
                    acc_no = random_generation_acc_number();
                }while(Bank.account_numbers.find(acc_no) != Bank.account_numbers.end());
                
                Bank.account_numbers.insert(acc_no);
                
                int account_choice;

                cout << "Enter the type of account tou want to create : " << endl;
                cout << " 1. For Bank Account" << endl;
                cout << " 2. For Saving Account " << endl;
                cin >> account_choice;

                switch(account_choice)  {
                    case 1: {
                        Account *temp = new Account(acc_no);
                        Bank.Accounts.push_back(temp);
                        temp->display();
                        break;
                    }
                    case 2:{
                        Account *temp = new Saving(acc_no);
                        Bank.Accounts.push_back(temp);
                        temp->display();
                    }
                    default:{
                        cout << "Choose an appropiate number " << endl;
                        break;
                    }
                }
                /*Account *temp = new Account(acc_no);
                Bank.Accounts.push_back(temp);
                temp->display();*/
                break;
            }
            case 2:{
                int acc_num;
                cout << "Enter the account number you want to know details about : " << endl;
                cin >> acc_num;

                for(int i = 0; i<Bank.Accounts.size(); i++){
                    if( acc_num == Bank.Accounts[i]->get_account_number()){
                        Bank.Accounts[i]->display();
                        break;
                    }
                }

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