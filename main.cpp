#include <iostream>
#include <vector>
#include <unordered_set>
#include "./include/Account.h"
#include "./include/Bank.h"
#include "./include/Utility.h"
#include "./include/Saving.h"
#include "./include/Errors.h"

using namespace std;

int main(){
    int choice {0};

    Bank Bank;
    
    while(1){
        
        main_display();
        try {
            choice = get_input_number();
        } catch  (const invalid_argument &error) {
            cout << error.what() << endl;
            continue;
        }

        if (choice == 7) {
            cout << "Thank you for trying us " << endl;
            break;
        }
        switch (choice) {
            case 1:{
                type_account_display(Bank);
                //save_account_details(temp, 1);
                break;
            }   
            case 2:{
                view_details_account_display(Bank);
                break;
            }
            case 3:{
                perform_operations_on_accounts(Bank);
                //cout << "Adding functionality to update existing account " << endl;
                break;
            }
            case 4:{
                get_a_loan(Bank);
                break;
            }
            case 5:{
                perform_operations_on_RD(Bank);
                break;
            }
            case 6:{
                close_bank_account(Bank);
                break;
            }
            default :{
                cout << "Please select appropiate option " << endl;
                break;
            }
        }

    }
    
}