// Write a C++ program to ask the user input coefficient values a and b of a linear
// equation, then solve it and print out result.
// ax + b = 0

#include <iostream>
using namespace std;

int main() {
    double a, b;
    cout << "Enter the value of coefficient a: ";
    cin >> a;
    cout << "Enter the value of coefficient b: ";
    cin >> b;

    if (a == 0) {
        if (b == 0) {
            cout << "Infinite solutions exist." << endl;
        } else {
            cout << "No solution exists." << endl;
        }
    } else {
        double x = -b / a;
        cout << "The solution for x is: " << x << endl;
    }

    return 0;
}