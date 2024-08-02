#include <iostream>
int main()
{
    std::cout << "Welcome to the Goblin Guide Adventure" << std::endl;

    // string to hold the players name
    std::string playerName;

    // get users name
    std::cout << "Please enter your name: ";
    std::cin >> playerName;

    std::cout << "Welcome " << playerName << " to the Goblin Guide adventure!" << std::endl;

    int choice;

    std::cout << "Where will " << playerName << " go?\n" << std::endl;
    std::cout << "1. Moonlight Markets" << std::endl;
    std::cout << "2. Grand Library" << std::endl;
    std::cout << "3. Shimmer Lake" << std::endl;
    std::cout << "Please enter your choice: ";
    std::cin >> choice;

        // Check the user's choice and display the corresponding messages
    if (choice == 1) {
        std::cout << "You chose Moonlight Markets" << std::endl;
    }
    else if (choice == 2) {
        std::cout << "You chose Grand Library" << std::endl;
    }
    else if (choice == 3) {
        std::cout << "You chose Shimmer Lake" << std::endl;
    }
    else {
        std::cout << "Invalid choice" << std::endl;
    }

    return 0;
}