// #define CATCH_CONFIG_MAIN
// #include "catch.hpp"
// #include <iostream>
// #include <sstream>
// #include <string>
// #include <cstdlib>
// #include <unistd.h>

// class AsciiArt {
// public:
//     static std::string dragonWelcomeArt;
//     static std::string knightArt;
//     static std::string mageArt;
//     static std::string thiefArt;
//     static std::string tankArt;
//     static std::string clericArt;
//     static std::string storyStartArt;
// };

// std::string AsciiArt::dragonWelcomeArt = "Welcome Dragon";
// std::string AsciiArt::knightArt = "Knight Art";
// std::string AsciiArt::mageArt = "Mage Art";
// std::string AsciiArt::thiefArt = "Thief Art";
// std::string AsciiArt::tankArt = "Tank Art";
// std::string AsciiArt::clericArt = "Cleric Art";
// std::string AsciiArt::storyStartArt = "Story Art";


// extern void displayWelcome();
// extern void displayMenu();
// extern void handleMenuChoice();
// extern void handleClassChoice();
// extern void startingStory();
// extern void pressAnyKeyToContinue2();


// TEST_CASE("Test displayWelcome", "[welcome]") {
//     std::stringstream input("3\n");
//     std::stringstream output;

//     std::streambuf* orig_cin = std::cin.rdbuf(input.rdbuf());
//     std::streambuf* orig_cout = std::cout.rdbuf(output.rdbuf());

//     displayWelcome();

//     std::cin.rdbuf(orig_cin);
//     std::cout.rdbuf(orig_cout);

//     REQUIRE(output.str().find("Welcome Dragon") != std::string::npos);
// }

// TEST_CASE("Test displayMenu and handleMenuChoice", "[menu]") {
//     std::stringstream input("3\n");
//     std::stringstream output;

//     std::streambuf* orig_cin = std::cin.rdbuf(input.rdbuf());
//     std::streambuf* orig_cout = std::cout.rdbuf(output.rdbuf());

//     handleMenuChoice();

//     std::cin.rdbuf(orig_cin);
//     std::cout.rdbuf(orig_cout);

//     REQUIRE(output.str().find("Welcome to Dungeon Dreams: The Goblin Guide!") != std::string::npos);
//     REQUIRE(output.str().find("Exiting game. Goodbye!") != std::string::npos);
// }

// TEST_CASE("Test displayCharacterClasses", "[character_classes]") {
//     std::stringstream input;
//     std::stringstream output;

//     std::streambuf* orig_cin = std::cin.rdbuf(input.rdbuf());
//     std::streambuf* orig_cout = std::cout.rdbuf(output.rdbuf());

//     displayCharacterClasses();

//     std::cin.rdbuf(orig_cin);
//     std::cout.rdbuf(orig_cout);

//     REQUIRE(output.str().find("Knight Art") != std::string::npos);
//     REQUIRE(output.str().find("Mage Art") != std::string::npos);
//     REQUIRE(output.str().find("Thief Art") != std::string::npos);
//     REQUIRE(output.str().find("Tank Art") != std::string::npos);
//     REQUIRE(output.str().find("Cleric Art") != std::string::npos);
// }

// TEST_CASE("Test startingStory", "[story]") {
//     std::stringstream input;
//     std::stringstream output;

//     std::streambuf* orig_cin = std::cin.rdbuf(input.rdbuf());
//     std::streambuf* orig_cout = std::cout.rdbuf(output.rdbuf());

//     startingStory();

//     std::cin.rdbuf(orig_cin);
//     std::cout.rdbuf(orig_cout);

//     REQUIRE(output.str().find("Story Art") != std::string::npos);
//     REQUIRE(output.str().find("One fateful morning, you set off for the capital, leaving behind your village and mundane life.") != std::string::npos);
// }

// TEST_CASE("Test pressAnyKeyToContinue2", "[user_interaction]") {
//     std::stringstream input("\n");
//     std::stringstream output;

//     std::streambuf* orig_cin = std::cin.rdbuf(input.rdbuf());
//     std::streambuf* orig_cout = std::cout.rdbuf(output.rdbuf());

//     pressAnyKeyToContinue2();

//     std::cin.rdbuf(orig_cin);
//     std::cout.rdbuf(orig_cout);

//     REQUIRE(output.str().find("Press enter to continue...") != std::string::npos);
// }