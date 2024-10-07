#ifndef INPUT_UTILS_H
#define INPUT_UTILS_H

#include <iostream>
#include <limits>

inline void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

#endif
