#include "../include/Account.h"
#include "../include/Bank.h"
#include "../include/Saving.h"
#include "../include/Recurring.h"
#include "../include/Fixed.h"
#include "../include/Errors.h"
#include "../include/Salary.h"
#include "../include/Utility.h"
#include "../include/Loan.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <limits>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>

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

template <typename T>
void delete_element(std::vector<T *>& vec, T &value) {
    /*auto it = std::find(vec.begin(), vec.end(), value);
    if (it != vec.end()) {
        vec.erase(it);
        return;
    } else {
        cout << "The account number was not found" << endl;
        return;
    }*/

   for(int i=0; i<vec.size(); i++){
    if(*vec[i] == value){
        vec.erase(vec.begin() + i);
        return;
    }
   }
   cout << "Account not found " << endl;
   return;
}

void flush_input(){
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void main_display(){
        cout << "Refer the catlaoug given below to perform the required task : " << endl;
        cout << " 1. Create new Account " << endl;
        cout << " 2. View account details " << endl;
        cout << " 3. Update existing account " << endl;
        cout << " 4. Get a loan " << endl;
        cout << " 5. Perform operations on RD " << endl;
        cout << " 6. Close Account " << endl;
        cout << " 7. To exit " << endl;
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
                        Account temp = (*obj.Accounts[i]);
                        cout << temp;
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
                obj.Recurring_deposits.push_back(temp);
                temp->display();
                save_RD_details(*temp, acc_num);
                //break;
                return;
            }
            case 2:{
                Fixed *temp = new Fixed(account);
                obj.Fixed_deposits.push_back(temp);
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
                transaction_details(*account, acc_num, "deposit", amount);
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
                transaction_details(*account, acc_num, "withdraw", amount);
                break;
            }
            case 5:{
                    account->deposit_salary();
                    //salary_transaction_details(*account, acc_num);
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

void save_RD_details(Recurring &obj, int flag = 1){
   
    ofstream file;
   // file.open("Files/RD_account_details.txt", ios::app);
    
    if(flag == 0){
        file.open("Files/RD_account_details.txt");
    }
    else if(flag == -1){
       file.open("Files/RD_account_details.txt"); 
       file.close();
       return;
    }
    else{
       file.open("Files/RD_account_details.txt", ios::app); 
    }

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
         << setw(20) << left << obj.get_account_number()
         << setw(20) << left << obj.get_RD_time_in_months()
         << setw(15) << left << obj.get_RD_intrest_rate()
         << left << obj.get_RD_creation_time_date() << endl;

    RD_FD_counter++;
    file.close();

}

void save_FD_details(Fixed &obj){
   
    ofstream file;
    file.open("Files/FD_account_details.txt", ios::app);

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

void update_RD_details(Bank &obj){
    RD_FD_counter = 1;
    int i = 0;
    if(obj.Recurring_deposits.size() == 0){
        save_RD_details(*obj.Recurring_deposits[i],-1);
    }
    while( i < obj.Recurring_deposits.size()){
        save_RD_details(*obj.Recurring_deposits[i],i);
        i++;
    }
}

void get_a_loan(Bank &obj){
    int acc_num;
    cout << "Enter the account number of the the loan bearer : " << endl;
    cin >> acc_num;
    int i = 0;
    for(i = 0; i<obj.Accounts.size(); i++){
                    if( acc_num == obj.Accounts[i]->get_account_number()){
                        Account temp = (*obj.Accounts[i]);
                        cout << temp;
                        break;
                    }
                }
    Account *temp = obj.Accounts[i];
    Loan *loan = new Loan(*temp);
    obj.Loan.push_back(loan);
    save_loan_details(*loan);
}

void perform_operations_on_RD(Bank &obj){
    int acc_num;
                cout << "Enter the account number of the Recurring Deposit : " << endl;
                cin >> acc_num;
                Recurring *temp;
                for(int i = 0; i < obj.Recurring_deposits.size(); i++){
                    if( acc_num == obj.Recurring_deposits[i]->get_account_number()){
                        temp = obj.Recurring_deposits[i];
                        temp->display();
                        break;
                    }
                }
     
    cout << "Choose appropriate operation operation on the RD : " << endl;
    cout << "1. Deposit money into Recurring Deposit " << endl;
    cout << "2. View Recurring Deposit Details " << endl;
    cout << "3. Break Recurring Deposit before maturity " << endl;
     start:
     int choice {0};
     try{
            choice = get_input_number();
        }catch (const invalid_argument &error){
            cout << error.what() << endl;
            goto start;
        }
    switch(choice){
        case 1:{
            temp->deposit();
            cout << "Deposit has been successfully made " << endl;
            update_RD_details(obj);
            return;
        }
        case 2:{
            temp->display();
            return;
        }
        case 3:{
            delete_element(obj.Recurring_deposits, *temp);
            update_RD_details(obj);
            break;
        }
        default: {
            cout << "please pick an appropriate option : " << endl;
            break;
        }
    }
    
}

void close_bank_account(Bank &obj){
    int acc_num;
        cout << "Enter the account number of the account you want to close " << endl;
        cin >> acc_num;
        int i;
                for(i = 0; i<obj.Accounts.size(); i++){
                    if( acc_num == obj.Accounts[i]->get_account_number()){
                        obj.Accounts[i]->display();
                        break;
                    }
                }
        Account *account = obj.Accounts[i];
        delete_element(obj.Accounts, *account);
        update_account_details_in_file(obj); 
}

void transaction_details(Account &obj, int acc_no, string transaction_type, double amount){
    
    string filename1 = "Files/";
    string filename2 = to_string(obj.get_account_number());
    string filename3 = ".txt";

    string filename = filename1 + filename2 + filename3;
    ofstream file;

    std::ifstream inFile(filename);
    bool file_exists = inFile.is_open(); // File exists if it can be opened
    inFile.close();
    
    file.open(filename.c_str(), ios::app);


    
    if(!file_exists){
        file << setw(5) <<  left <<"Sr No." 
             << setw(30) << left <<"Name " 
             << setw(15) << left <<"transaction amount " 
             << setw(20) << left <<"transaction type" 
             << setw(20) << left << "date and time of transaction" << endl;
    }

    if(transaction_type == "deposit") obj.deposit_counter++;
    if(transaction_type == "withdraw") obj.withdraw_counter++;

    file      << setw(30) << left << obj.get_account_holder() 
             << setw(15) << left << amount 
             << setw(20) <<  left << transaction_type 
             << setw(20) << left << get_current_time_date() << endl;

    file.close();
    
}

static int loan_counter {1};

void save_loan_details(Loan &obj){
    ofstream file;
    
       file.open("Files/loan_details.txt", ios::app); 

    if(!file){
        cout << "Error opening file : " << endl;
    }

    if(loan_counter == 1){
        file << setw(10) << left << "Sr No."
         << setw(30) << left << "Name"
         << setw(20) << left << "Loan type"
         << setw(20) << left << "Account Number"
         << setw(15) << left << "Loan intrest"
         << setw(20) << left << "Loan time"
         << setw(20) << left << "Loan amount"
         << left << "Date of creation" << endl;
    }

    file << setw(10) << left << loan_counter
         << setw(30) << left << obj.get_loan_account_holder()
         << setw(20) << obj.get_loan_type()
         << setw(20) << left << obj.get_account_number()
         << setw(20) << left << obj.get_loan_intrest()
         << setw(20) << left << obj.get_loan_time()
         << setw(20) << left << obj.get_loan_amount()
         << left << obj.get_creation();
    loan_counter++;

    file.close();

}

/*void salary_transaction_details(Account &obj, int acc_no){

    ofstream file;

    string filename1 = "Files/";
    string filename2 = to_string(obj.get_account_number());
    string filename3 = ".txt";

    string filename = filename1 + filename2 + filename3;

    std::ifstream inFile(filename);
    bool file_exists = inFile.is_open(); // File exists if it can be opened
    inFile.close();

    file.open(filename.c_str(), ios::app);

    if(file_exists){
        file << setw(30) << left <<"Name " 
             << setw(15) << left <<"transaction amount " 
             << setw(20) << left <<"transaction type" 
             << setw(20) << left << "date and time of transaction" << endl;
    }

    obj.sr_no++;

    file     << setw(30) << left << obj.get_account_holder() 
             << setw(15) << left << obj.get_salary()
             << setw(20) <<  left << "Monthly Salary" 
             << setw(20) << left << get_current_time_date() << endl;

    file.close();

}*/
