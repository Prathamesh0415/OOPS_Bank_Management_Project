#include "../include/Account.h"
#include "../include/Bank.h"
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