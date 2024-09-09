/*Try-Catch statement. Write a program to
a. Ask the user to enter two double values a and b for division (a/b). Throw an exception if b is
0, and ask the user to re-enter value for b.
b. Write a loop that continuously request 1MB from the heap (as an array of char). Catch the
exception to stop the loop if allocation fails and print out how much memory has been
allocated.
Check with physical size of RAM and Page file memories of your computer (using dxdiag
command). Does it makes sense ?*/

#include <iostream>
#include <stdexcept> // For standard exceptions
using namespace std;

// Function for division with exception handling
double divide(double a, double b) {
    if (b == 0.0) {
        throw runtime_error("Division by zero is not allowed."); // Throw exception if b is 0
    }
    return a / b;
}

// Function for continuous memory allocation (1MB blocks)
void allocateMemory() {
    size_t totalMemoryAllocated = 0;
    const size_t blockSize = 1024 * 1024; // 1 MB

    try {
        while (true) {
            char* block = new char[blockSize]; // Request 1MB from heap
            totalMemoryAllocated += blockSize; // Increase total allocated memory
        }
    } catch (const bad_alloc&) { // Catch bad_alloc exception when memory allocation fails
        cout << "Memory allocation failed after allocating " << totalMemoryAllocated / (1024 * 1024) 
             << " MB." << endl;
    }
}

int main() {
    // a. Division with exception handling
    double a, b;
    bool validInput = false;

    cout << "Enter two numbers for division (a / b):" << endl;

    while (!validInput) {
        try {
            cout << "Enter value for a: ";
            cin >> a;
            cout << "Enter value for b: ";
            cin >> b;

            double result = divide(a, b); // Attempt division
            cout << "Result of " << a << " / " << b << " = " << result << endl;
            validInput = true; // Division successful, exit loop

        } catch (const runtime_error& e) {
            cout << e.what() << " Please re-enter value for b." << endl;
        }
    }

    // b. Continuous memory allocation until failure
    cout << "\nNow attempting to allocate memory continuously..." << endl;
    allocateMemory();

    return 0;
}