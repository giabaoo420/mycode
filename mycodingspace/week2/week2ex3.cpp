// Write a C++ program to
// a) Read a string from the console input, store the string in character array str. Then print out its
// all characters, separated by a space.
// b) Print 1.234 with 9-character width, padded by zeros.
// c) Print 1.234 with precision is 2 digits of fractional part (after decimal point).
// d) Read a hexadecimal value (preceded by 0x) into variable hex, then print out its decimal
// value and hexa form.
// Input: 0x10
// Output: 16 0x10

#include <iostream>
#include <iomanip>
#include <sstream>

int main() {
    // a) Read a string and print its characters separated by a space
    std::string str;
    std::cout << "Enter a string: ";
    std::getline(std::cin, str);
    for (char c : str) {
        std::cout << c << " ";
    }
    std::cout << std::endl;

    // b) Print 1.234 with 9-character width, padded by zeros
    std::cout << std::setw(9) << std::setfill('0') << 1.234 << std::endl;

    // c) Print 1.234 with precision of 2 digits after the decimal point
    std::cout << std::fixed << std::setprecision(2) << 1.234 << std::endl;

    // d) Read a hexadecimal value and convert it to decimal and hex form
    std::string hex_str;
    std::cout << "Enter a hexadecimal value (e.g., 0x10): ";
    std::cin >> std::hex >> hex_str;
    int hex_dec = std::stoi(hex_str, nullptr, 16);
    std::cout << hex_dec << " " << hex_str << std::endl;

    return 0;
}