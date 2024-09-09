/*Duplicate and modify the program of question 1 so that name attribute is a pointer, which is
dynamically allocated in heap memory via the class constructor. Write a destructor to free up
memory allocated for it (when a Book object is destroyed).
*/

#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string* name;  // Pointer to dynamically allocated memory for the name
    int price;

public:
    // Constructor to dynamically allocate memory for name
    Book(string n = "", int p = 0) {
        name = new string(n);  // Dynamically allocate memory for name
        price = p;
    }

    // Destructor to free dynamically allocated memory
    ~Book() {
        delete name;  // Free the dynamically allocated memory for name
    }

    // Copy constructor (deep copy)
    Book(const Book& other) {
        name = new string(*other.name);  // Allocate new memory and copy value
        price = other.price;
    }

    // Assignment operator (deep copy)
    Book& operator=(const Book& other) {
        if (this != &other) {
            delete name;  // Free existing memory
            name = new string(*other.name);  // Allocate new memory and copy value
            price = other.price;
        }
        return *this;
    }

    // Getter for price
    int getPrice() const {
        return price;
    }

    // Print book information
    void printInfo() const {
        cout << "Name: " << *name << ", Price: " << price << endl;
    }
};

int main() {
    // a) Create three Book objects using dynamic memory allocation and initialize values for them
    Book* book1 = new (nothrow) Book("Book 1", 25);
    Book* book2 = new (nothrow) Book("Book 2", 35);
    Book* book3 = new (nothrow) Book("Book 3", 20);

    // Check for NULL pointer to detect whether the allocations succeeded or not
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

    // Free up memory space for each object
    delete book1;
    delete book2;
    delete book3;

    // b) Ask the user to enter a number n, create an array of n Book objects using dynamic memory allocation
    int n;
    cout << "Enter the number of books: ";
    cin >> n;
    cin.ignore();  // Ignore the newline character after the integer input

    // Dynamically allocate an array of n Book objects
    Book* bookArray = new (nothrow) Book[n];

    // Check for NULL pointer to detect whether the allocations succeeded or not
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
        cin.ignore();  // Ignore the newline character after the integer input
        bookArray[i] = Book(name, price);  // Use the constructor to initialize each book
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