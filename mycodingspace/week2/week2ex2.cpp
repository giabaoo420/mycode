// In C++, a hexadecimal can be indicated by prefix 0x following by hexadecimal digits (0-9, A-F),
// e.g., 0x7AB9.
// Write a C++ program that takes in one user input argument from the command line and
// checks if it is valid hexadecimal number or not, then displays the hexadecimal number to the
// console.
// • If the incorrect number of user input arguments is detected, the program must exit with an
// error
// • The letter "x" in 0x and each hexadecimal digit (0-9, A-F) can be lower case or upper case.
// Example Run:
// ./a.exe 0xA5B
// > Got valid hexadecimal value: 0xA5B

#include <iostream>
#include <string>
#include <cstdlib>

bool isValidHexadecimal(const std::string& input) {
    size_t pos;
    long value = std::stol(input, &pos, 16);
    return pos == input.size();
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Error: Incorrect number of arguments. Usage: ./a.exe <hex_value>\n";
        return 1;
    }

    std::string input = argv[1];
    if (isValidHexadecimal(input)) {
        std::cout << "Got valid hexadecimal value: " << input << std::endl;
    } else {
        std::cerr << "Error: Invalid hexadecimal value.\n";
        return 1;
    }

    return 0;
}