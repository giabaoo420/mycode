/*rite a C++ program which asks the user to input the total amount of seconds, and convert it to
hours, minutes, and seconds.*/


#include <iostream>

int main() {
    // Variable to hold the total seconds input by the user
    long totalSeconds;

    // Prompt the user for input
    std::cout << "Enter the total amount of seconds: ";
    std::cin >> totalSeconds;

    // Validate the input
    if (totalSeconds < 0) {
        std::cout << "Please enter a non-negative number of seconds." << std::endl;
        return 1; // Exit with an error code
    }

    // Calculate hours, minutes, and seconds
    long hours = totalSeconds / 3600; // 1 hour = 3600 seconds
    long minutes = (totalSeconds % 3600) / 60; // Remaining seconds converted to minutes
    long seconds = totalSeconds % 60; // Remaining seconds

    // Output the result
    std::cout << totalSeconds << " seconds is equivalent to: " << std::endl;
    std::cout << hours << " hours, " << minutes << " minutes, and " << seconds << " seconds." << std::endl;

    return 0; // Successful execution
}