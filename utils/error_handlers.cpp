#include <iostream>
#include <limits>
#include "../include/Utility.h"
#include "../include/Errors.h"

using namespace std;

int get_input_number(){
    int choice {0};
    cout << "Enter you choice : " << endl;
    cin >> choice;
    if( cin.fail() ){ // cin.fail() checks wehter the input has failed or not
        cin.clear(); // clears the error flag
        flush_input(); // for clearing the input stream
        throw invalid_argument("Invalid input please enter appropriate choice");
    } else {
        return choice;
    }
}    

double get_deposit_amount(){
    double amount;
    cin >> amount;
    if( cin.fail() ){
        cin.clear();
        flush_input();
        throw invalid_argument("Please enter a valid amount");
    }else if(amount <10000){
        throw "The deposit amount should be greater than 10,000 " ;
    }
}