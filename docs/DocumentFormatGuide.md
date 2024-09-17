# Document Format Guide

## Format Best Practices

To all contributors of this project, to ensure the efficiency and effectiveness of planning, testing, and deployment, please follow these best practices:

## Reason This is Important

Adhering to these formatting and best practice guidelines helps maintain code quality and project stability. Proper formatting and consistent practices lead to:
- **Improved Readability**: Clear and consistent code is easier to read and understand, reducing the time required for reviews and debugging.
- **Enhanced Maintainability**: Consistent practices make the codebase easier to maintain and update, allowing for smoother integrations and fewer errors.
- **Increased Security**: Following security best practices helps protect the project from vulnerabilities and potential exploits.
- **Effective Collaboration**: A unified approach to formatting and security ensures all contributors are on the same page, facilitating better teamwork and project management.

## Rules of Formatting

### Classes (.cpp)

- **Naming Conventions**: Use PascalCase for class names. Names should be descriptive and reflect the class's role or functionality.
  - **Example**: `StartScreen.cpp`
- **Function declaration**: Don't bother declaring functions at the top of the class. Unless it is a Class Object like Player.cpp or Item.cpp
  
- **Libraries**: Format the importables by organising them in order of standard libraries then third-party libraries. Ideally, namespaces shouldn't be used. Namespaces ruin readability, adds pollution, and maintenance challenges.
  - **Example**:
    ```cpp
    #include <iostream>
    #include <thread>
    #include "utils.h"
    // DO NOT USE 'using namespace std;'
    ```

- **Documentation**: Doxygen comments should be below the library declarations and include declarations. They should contain (the bare minimum): @file, @author, and @brief. These may include @return and @param whenever necessary.
  - **Example**:
    ```cpp
    /**
     * @file
     * @brief Main class for our game. Contains the game loop
     * @author Elizabeth Stewart
     * @author Lucy Hadden
     * 
     */
    int main()
    {
        // Implementation...
    }
    ```

### Includes/Headers (.h)

- **Naming Conventions**: Use PascalCase for header names. Names should be descriptive and reflect the class's role or functionality.

- **Avoid Redundancy**: Only include files or libraries that are necessary for the current file. Remove unused directives to keep the code clean and prevent potential conflicts.

### Functions/Methods Specific Rules

- **Naming Conventions**: Use PascalCase for method names. Names should be action-oriented and descriptive of the method's functionality. Variables should be in camelCase.
  
  - **Example**: `bool gameRunning;`,`playerStats(playerClass);`
    ```cpp
    /**
     * @file
     * @brief Main class for our game. Contains the game loop
     * @author Elizabeth Stewart
     * @author Lucy Hadden
     * 
     */
    int main()
    {
    bool gameRunning = true;
    bool gameCompleted = false;
    // ...

    displayWelcome();
    resetPlayerStats(playerStats, playerClass)
    // ...
    }
    ```

- **Brackets**: Curly bracket indentation should be on a new line.
  - **Example**: 
    ```cpp
    int main()
    {
    // implementation...
    }
    ```


- **Documentation**: See class documentation above for [Documentation](#classes-cpp)
  
- **Comments**: Comments and single line comments are valuable and encouraged when methods are difficult to understand.

### Tests (.cpp)

- **To be determined**: ...

### Extra Rules

- **To be determined**: ...

## Summary

By adhering to this Document Format Guide, contributors will help maintain a high standard of code quality, security, and collaboration within the project. Consistent formatting and up-to-date practices ensure that the project remains efficient, secure, and manageable.

For any questions or clarifications regarding this guide, please contact the project lead (mailto:hadlu202@student.otago.ac.nz) with any questions or concerns.