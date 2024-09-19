#ifndef TEST_UTILS_H
#define TEST_UTILS_H


/**
 * @file
 * @brief Header file to mock the sleep and system clear methods for testing
 * @author Lucy Hadden
 */

/**
 * @brief Method to mock the sleep method
 */
void mockSleep(int seconds);

/**
 * @brief method to mock the system clear method
 */
void mockSystemClear();

#endif // TEST_UTILS_H
