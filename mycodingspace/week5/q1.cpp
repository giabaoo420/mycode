// Dynamic memory allocation for objects
// Write a C++ program which defines a class named Book with two private attributes name
// (string) and price (integer). Provide constructor to initialize those attributes.
// a) Create three Book objects using dynamic memory allocation and initialize values for them
// through the constructor. You should check for NULL pointer to detect whether the allocations
// are succeeded or not.
// Use range-based for loop to print out all information of the objects, and free up memory space
// after that.
// b) Ask the user to enter a number n. Create an array of n Book objects using dynamic memory
// allocation and ask the user to input value for them.
// Print out the most expensive book. Free up memory space after that.


#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string name;
    int price;

public:
    // Constructor to initialize name and price
    Book(string n = "", int p = 0) {
        name = n;
        price = p;
    }

    // Getter for price
    int getPrice() const {
        return price;
    }

    // Print book information
    void printInfo() const {
        cout << "Name: " << name << ", Price: " << price << endl;
    }
};

int main() {
    // a) Create three Book objects using dynamic memory allocation and initialize values for them
    Book* book1 = new (nothrow) Book("Book 1", 25);
    Book* book2 = new (nothrow) Book("Book 2", 35);
    Book* book3 = new (nothrow) Book("Book 3", 20);

    // Check for NULL pointer to detect whether the allocations are succeeded or not
    if (book1 == nullptr || book2 == nullptr || book3 == nullptr) {
        cout << "Memory allocation failed." << endl;
        return 1;
    }

    // Use range-based for loop to print out all information of the objects
    cout << "Book information:" << endl;
    Book* books[] = {book1, book2, book3};
    for (Book* book : books) {
        book->printInfo();
    }

    // Free up memory space
    delete book1;
    delete book2;
    delete book3;

    // b) Ask the user to enter a number n, create an array of n Book objects using dynamic memory allocation
    int n;
    cout << "Enter the number of books: ";
    cin >> n;
    cin.ignore(); // Ignore the newline character after the integer input

    // Dynamically allocate an array of n Book objects
    Book* bookArray = new (nothrow) Book[n];

    // Check for NULL pointer to detect whether the allocations are succeeded or not
    if (bookArray == nullptr) {
        cout << "Memory allocation failed." << endl;
        return 1;
    }

    // Ask the user to input values for the Book objects
    cout << "Enter book information:" << endl;
    for (int i = 0; i < n; i++) {
        string name;
        int price;
        cout << "Book " << i + 1 << ":" << endl;
        cout << "Name: ";
        getline(cin, name);
        cout << "Price: ";
        cin >> price;
        cin.ignore(); // Ignore the newline character after the integer input
        bookArray[i] = Book(name, price); // Use the parameterized constructor
    }

    // Find the most expensive book
    Book* mostExpensiveBook = &bookArray[0];
    for (int i = 1; i < n; i++) {
        if (bookArray[i].getPrice() > mostExpensiveBook->getPrice()) {
            mostExpensiveBook = &bookArray[i];
        }
    }

    // Print the most expensive book
    cout << "The most expensive book is:" << endl;
    mostExpensiveBook->printInfo();

    // Free up memory space
    delete[] bookArray;

    return 0;
}