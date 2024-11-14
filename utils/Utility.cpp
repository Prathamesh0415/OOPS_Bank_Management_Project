#include "../include/Account.h"
#include "../include/Bank.h"
#include "../include/Saving.h"
#include "../include/Recurring.h"
#include "../include/Fixed.h"
#include "../include/Errors.h"
#include "../include/Salary.h"
#include "../include/Utility.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <limits>
#include <fstream>
#include <iomanip>
#include <vector>

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

Account type_account_display(Bank &obj){
    int acc_no = {000000};
                do{
                    acc_no = random_generation_acc_number();
                }while(obj.account_numbers.find(acc_no) != obj.account_numbers.end());
                
                obj.account_numbers.insert(acc_no);
                
                int account_choice;
                start:
                cout << "Enter the type of account tou want to create : " << endl;
                cout << " 1. For Bank Account" << endl;
                cout << " 2. For Saving Account " << endl;
                cout << " 3. For Salary Account " << endl;
                //cin >> account_choice;

                try {
                    account_choice = get_input_number();
                } catch (const invalid_argument &error){
                    cout << error.what() << endl;
                    goto start;
                }

                switch(account_choice)  {
                    case 1: {
                        std::string name;
                        double amount;
                        flush_input();
                        std::cout << "Enter the name of the account holder : ";
                        std::getline(std::cin, name);
                        start1:
                        std::cout << "Enter the Deposit amount : " ;
                        try{
                            amount = get_deposit_amount(acc_no);
                        } catch (const invalid_argument &error){
                            cout << error.what() << endl;
                            goto start1;
                        } catch (string error){
                            cout << error << endl;
                            goto start1;
                        }
                        Account *temp = new Account(acc_no, name, amount);
                        obj.Accounts.push_back(temp);
                        temp->display();
                        return *temp;
                    }
                    case 2:{
                        double intrest;
                        std::string name;
                        double amount;
                        flush_input();
                        std::cout << "Enter the name of the account holder : ";
                        std::getline(std::cin, name);
                        start2:
                        cout << "Enter the intrest rate : " << endl;
                        try{
                            intrest = get_intrest_rate();
                        }catch(const invalid_argument &error){
                            cout << error.what() << endl;
                            goto start2;
                        }catch(string &error){
                            cout << error << endl;
                            goto start2;
                        }
                        start3:
                        std::cout << "Enter the Deposit amount : " ;
                        try{
                            amount = get_deposit_amount(acc_no);
                        } catch (const invalid_argument &error){
                            cout << error.what() << endl;
                            goto start3;
                        } catch (string error){
                            cout << error << endl;
                            goto start3;
                        }
                        Account *temp = new Saving(acc_no, name, intrest, amount);
                        obj.Accounts.push_back(temp);
                        temp->display();
                        return *temp;
                    }
                    case 3:{
                        std::string name;
                        double salary;
                        flush_input();
                        std::cout << "Enter the name of the account holder : ";
                        std::getline(std::cin, name);
                        start4:
                        cout << " Enter the salary amount " << endl;
                        try{
                            salary = get_deposit_amount(acc_no);
                        } catch (const invalid_argument &error){
                            cout << error.what() << endl;
                            goto start4;
                        } catch (string error){
                            cout << error << endl;
                            goto start4;
                        }
                        Account *temp = new Salary(acc_no, salary, name);
                        obj.Accounts.push_back(temp);
                        temp->display();
                        return *temp;
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
        start:
        cout << "Enter the number corresponding to the operation you want to perform : " << endl;
        cout << "1. To create a Recurring Deposit " << endl;
        cout << "2. To create a Fixed deposit " << endl;
        cout << "3. To deposit money into bank account " << endl;
        cout << "4. To withdraw money from bank account " << endl;
        cout << "5. To deposit salary into salary account " << endl;
        try{
            choice = get_input_number();
        }catch (const invalid_argument &error){
            cout << error.what() << endl;
            goto start;
        }
        switch (choice){
            case 1:{
                Recurring *temp = new Recurring(account);
                temp->display();
                save_RD_details(*temp);
                //break;
                return;
            }
            case 2:{
                Fixed *temp = new Fixed(account);
                temp->display();
                save_FD_details(*temp);
                //break;
                return;
            }
            case 3:{
                double amount;
                start1:
                cout << "Enter the amount to be deposited in the bank acount : " << endl;
                try{
                    amount = get_deposit_amount(1);
                } catch(const invalid_argument &error){
                    cout << error.what() << endl;
                    goto start1;
                } catch (string &error){
                    cout << error << endl;
                    goto start1;
                }
                account->deposit(amount);
                update_account_details_in_file(obj);
                break;
            }
            case 4:{
                double amount;
                start2:
                cout << "Enter the amount you want to deposit from the account : " << endl;
                try{
                    amount = get_withdraw_amount(*account);
                } catch (const invalid_argument &error) {
                    cout << error.what() << endl;
                    goto start2;
                } catch (string &error) {
                    cout << error << endl;
                    goto start2;
                }
                account->withdraw(amount);
                update_account_details_in_file(obj);
                break;
            }
            default : {
                cout << "Enter appropriate choice : " << endl;
                break;
            }
        }
}

static int account_counter {1};

void save_account_details(Account &obj, int flag = 1){
    
    ofstream file;
    if(flag == 0){
    file.open("Files/account_details.txt");
    }else{
       file.open("Files/account_details.txt", ios::app); 
    }

    if(!file){
        cout << "Error opening file : " << endl;
    }

    if(account_counter == 1){
        file << setw(10) << left << "Sr No."
         << setw(30) << left << "Name"
         << setw(20) << left << "Account type"
         << setw(20) << left << "Account Number"
         << setw(20) << left << "Account Balance"
         << left << "Date of creation" << endl;
    }

    file << setw(10) << left << account_counter
         << setw(30) << left << obj.get_account_holder()
         << setw(20) << obj.get_account_type()
         << setw(20) << left << obj.get_account_number()
         << setw(20) << left << obj.get_balance()
         << left << obj.get_creation_time_date();
    account_counter++;

    file.close();
}

 static int RD_FD_counter {1};

void save_RD_details(Recurring &obj){
   
    ofstream file;
    file.open("Files/RD_FD_account_details.txt", ios::app);
    
    if(!file){
        cout << "Error opening file : " << endl;
    }

    if(RD_FD_counter == 1){
        file << setw(10) << left << "Sr No."
         << setw(30) << left << "Name"
         << setw(20) << left << "Deposit type"
         << setw(20) << left << "Account Number"
         << setw(20) << left << "Maturity time"
         << setw(15) << left << "Intrest"
         << left << "Date of creation" << endl;
    }

    file << setw(10) << left << RD_FD_counter
         << setw(30) << left << obj.get_RD_account_holder()
         << setw(20) << left << obj.get_deposit_type()
         << setw(20) << left << obj.get_RD_account_number()
         << setw(20) << left << obj.get_RD_time_in_months()
         << setw(15) << left << obj.get_RD_intrest_rate()
         << left << obj.get_RD_creation_time_date() << endl;

    RD_FD_counter++;
    file.close();

}

void save_FD_details(Fixed &obj){
   
    ofstream file;
    file.open("Files/RD_FD_account_details.txt", ios::app);

    if(!file){
        cout << "Error opening file : " << endl;
    }

    if(RD_FD_counter == 1){
        file << setw(10) << left << "Sr No."
         << setw(30) << left << "Name"
         << setw(20) << left << "Deposit type"
         << setw(20) << left << "Account Number"
         << setw(20) << left << "Maturity time"
         << setw(15) << left << "Intrest"
         << left << "Date of creation" << endl;
    }

    file << setw(10) << left << RD_FD_counter
         << setw(30) << left << obj.get_FD_account_holder()
         << setw(20) << left << obj.get_deposit_type()
         << setw(20) << left << obj.get_FD_account_number()
         << setw(20) << left << obj.get_FD_time_in_months()
         << setw(15) << left << obj.get_FD_intrest_rate()
         << left << obj.get_FD_creation_time_date() << endl;

    RD_FD_counter++;
    file.close();

}

void update_account_details_in_file(Bank &obj){
    account_counter = 1;
    int i = 0;
    while( i < obj.Accounts.size()){
        save_account_details(*obj.Accounts[i],i);
        i++;
    }       
}

