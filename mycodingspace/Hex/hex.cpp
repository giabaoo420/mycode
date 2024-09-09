#include <iostream>
#include <sstream>
using namespace std;

int main() {
    int hexvalue;
    stringstream ss;
    string str = "0xFF";

    ss << str;
    ss >> hex >> hexvalue;
    cout << "hex in decimal " << hexvalue << "\n";
    cout << "the hex value in hex format is " << hex << uppercase << showbase << hexvalue << "\n";
}