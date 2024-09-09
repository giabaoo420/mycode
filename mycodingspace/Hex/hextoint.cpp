#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "Usage: " << argv[0] << " <integer|hexadecimal>" << endl;
        return 1;
    }

    string input = argv[1];
    bool isHex = false;

    // Check if the input is hexadecimal
    for (char c : input) {
        if (!isxdigit(c)) {
            isHex = false;
            break;
        }
        isHex = true;
    }

    if (isHex) {
        // Convert hexadecimal to integer
        int value = stoi(input, nullptr, 16);
        cout << "Hexadecimal " << input << " is equal to decimal " << value << endl;
    } else {
        // Convert integer to hexadecimal
        int value = stoi(input);
        cout << "Decimal " << value << " is equal to hexadecimal 0x" << hex << value << endl;
    }

    return 0;
}