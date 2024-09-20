#include <cstdlib>
#include <iostream>
#include "utils.h"

#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif

using namespace std; // Use the standard namespace

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
        cout << "\033[2J\033[1;1H"; // ANSI escape code to clear the console
        //std::cout << "\033c";
    #else
        cout << "\033[2J\033[1;1H"; // ANSI escape code to clear the console
    #endif
}
