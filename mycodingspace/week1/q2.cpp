//  Create an array of 5 integers. Ask the user to enter values for them, then print out the
// maximum value and their average


#include <iostream>

int main() {
    int arr[5];
    int sum = 0;
    
    for (int i = 0; i < 5; ++i) {
        std::cout << "Enter value for element " << i << ": ";
        std::cin >> arr[i];
        sum += arr[i];
    }

    int max = arr[0];
    for (int i = 1; i < 5; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    double average = static_cast<double>(sum) / 5;

    std::cout << "Maximum value: " << max << std::endl;
    std::cout << "Average: " << average << std::endl;

    return 0;
}