#ifndef UTILS_H
#define UTILS_H

#ifdef __APPLE__ // macOS
    #include <unistd.h>
#else
    #include <windows.h> // windows
#endif

// Sleep function in seconds
void sleep(short seconds) {
    #ifdef __APPLE__
        sleep(seconds);
    #else
        Sleep(second * 1000);
    #endif
}

void clear(){
    #ifdef __APPLE__
        system("clear");
    #else
        system("cls");
    #endif
}

#endif