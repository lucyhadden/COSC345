#include "utils.h"
#include <cstdlib> 
#include <unistd.h>

// sleep function delays next command (by x seconds)
void customSleep(short seconds) {
    #ifdef _WIN32
        Sleep(seconds * 1000); // Windows-specific function (milliseconds)
    #else
        ::sleep(seconds); // POSIX sleep function (seconds)
    #endif
}

// clear function removes all text on terminal
void clear() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
