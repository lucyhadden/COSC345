#include "utils.h"
#include <cstdlib> 

// sleep function delays next command (by x seconds)
void sleep(short seconds) {
    #ifdef __APPLE__
        ::sleep(seconds);
    #else
        Sleep(second * 1000); // converted from milliseconds
    #endif
}

// clear function removes all text on terminal
void clear(){
    #ifdef __APPLE__
        system("clear");
    #else
        system("cls");
    #endif
}
