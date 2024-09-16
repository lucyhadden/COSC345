#include <cstdlib>
#include <iostream>
#include "utils.h"

#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif

// sleep function delays next command (by x seconds)
void CustomSleep(short seconds) {
    #ifdef _WIN32
        Sleep(seconds * 1000); // Windows-specific function (milliseconds)
    #else
        sleep(seconds); // POSIX sleep function (seconds)
    #endif
}

// clear function removes all text on terminal
void Clear() {
    #ifdef _WIN32
        system("cls");
        //std::cout << "\033c";
    #else
        system("clear");
    #endif
}
