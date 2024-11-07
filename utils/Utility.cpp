#include "../include/Account.h"
#include "../include/Bank.h"
#include "../include/Saving.h"
#include "../include/Recurring.h"
#include "../include/Fixed.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <limits>

using namespace std;

string get_current_time_date(){
    time_t timestamp;
    time(&timestamp);

    return ctime(&timestamp);
}

int random_generation_acc_number(){
    srand(time(0)); // seeding the random number generator to current time;
    int random_number = 100000 + rand()%900000;
    return random_number;
}

void flush_input(){
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void main_display(){
        cout << "Refer the catlaoug given below to perform the required task : " << endl;
        cout << " 1. Create new Account " << endl;
        cout << " 2. View account details " << endl;
        cout << " 3. Update existing account " << endl;
        cout << " 4. Exit " << endl;
}

void type_account_display(Bank &obj){
    int acc_no = {000000};
                do{
                    acc_no = random_generation_acc_number();
                }while(obj.account_numbers.find(acc_no) != obj.account_numbers.end());
                
                obj.account_numbers.insert(acc_no);
                
                int account_choice;

                cout << "Enter the type of account tou want to create : " << endl;
                cout << " 1. For Bank Account" << endl;
                cout << " 2. For Saving Account " << endl;
                cin >> account_choice;

                switch(account_choice)  {
                    case 1: {
                        Account *temp = new Account(acc_no);
                        obj.Accounts.push_back(temp);
                        temp->display();
                        break;
                    }
                    case 2:{
                        Account *temp = new Saving(acc_no);
                        obj.Accounts.push_back(temp);
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
}

void view_details_account_display(Bank &obj){
    int acc_num;
                cout << "Enter the account number you want to know details about : " << endl;
                cin >> acc_num;

                for(int i = 0; i<obj.Accounts.size(); i++){
                    if( acc_num == obj.Accounts[i]->get_account_number()){
                        obj.Accounts[i]->display();
                        break;
                    }
                }
}

void perform_operations_on_accounts(Bank &obj){
    int acc_num;
        cout << "Enter the account number you want to perform operations on : " << endl;
        cin >> acc_num;
        int i;
                for(i = 0; i<obj.Accounts.size(); i++){
                    if( acc_num == obj.Accounts[i]->get_account_number()){
                        obj.Accounts[i]->display();
                       
                        break;
                    }
                }
        Account *account = obj.Accounts[i];
        int choice;
        cout << "Enter the number corresponding to the operation you want to perform : " << endl;
        cout << "1. To create a Recurring Deposit " << endl;
        cout << "2. To create a Fixed deposit " << endl;
        cin >> choice;
        switch (choice){
            case 1:{
                Account *temp = new Recurring(account);
                temp->display();
                //break;
                return;
            }
            case 2:{
                Account *temp = new Fixed(account);
                temp->display();
                //break;
                return;
            }
            default : {
                cout << "Enter appropriate choice : " << endl;
                break;
            }
        }
       
        

}
