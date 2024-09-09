// Write a C++ program to ask the user to input a string, then replace the lowercase
// characters by uppercase and vice versa, and print out the sum of digits in the string.
// Sample Run:
// Input a string: Hello123 45abc
// -> Converted String: hELLO123 45ABC
// -> Sum of all digits in the string: 15

#include <iostream>
#include <cctype>

int main() {
    std::string input;
    std::cout << "Input a string: ";
    std::getline(std::cin, input);

    for (char &c : input) {
        if (std::islower(c)) {
            c = std::toupper(c);
        } else if (std::isupper(c)) {
            c = std::tolower(c);
        }
    }

    int sum = 0;
    for (char c : input) {
        if (std::isdigit(c)) {
            sum += c - '0';
        }
    }

    std::cout << "-> Converted String: " << input << std::endl;
    std::cout << "-> Sum of all digits in the string: " << sum << std::endl;

    return 0;
}