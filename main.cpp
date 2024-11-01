#include <iostream>
#include <vector>
#include <unordered_set>
#include "./include/Account.h"
#include "./include/Bank.h"
#include "./include/Utility.h"

using namespace std;

int main(){
    int choice {0};

    Bank Bank;
    
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
        switch (choice) {
            case 1:{
                int acc_no = {000000};
                do{
                    acc_no = random_generation_acc_number();
                }while(Bank.account_numbers.find(acc_no) != Bank.account_numbers.end());
                
                Bank.account_numbers.insert(acc_no);
                
                Account *temp = new Account(acc_no);
                Bank.Accounts.push_back(temp);
                temp->display();
                
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