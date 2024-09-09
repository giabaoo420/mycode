/*Write a C++ program which can work with command line arguments below:
Get two numbers (each could be either hexadecimal or decimal) with an operator sign (+ or -) then
print out result.
Sample Run:
./a.exe 0x12 + 10
Result is: 28
./a.exe 100 – 0x1A
Result is: 74*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 4) {
        cerr << "Usage: " << argv[0] << "<number1> <operator> <number2>\n";
        return 1;
    }
    string num1_str = argv[1];
    string op = argv[2];
    string num2_str = argv[3];

    int num1;
    if (num1_str.find("0x") == 0) {
        num1 = strtol(num1_str.c_str(), nullptr, 16);
    } else {
        num1 = strtol(num1_str.c_str(), nullptr, 10);
    }

    int num2;
    if(num2_str.find("0x") == 0) {
        num2 = strtol(num2_str.c_str(), nullptr, 16);
    } else {
        num2 = strtol(num2_str.c_str(), nullptr, 10);
    }

    int result;
    if(op == "+") {
        result = num1 + num2;
    } else if (op == "-") {
        result = num1 - num2;
    } else {
        cerr << "invalid operator. Use + or -.\n";
        return 1;
    }
   
    cout << "result is: " << result << endl;
    return 0;
}
