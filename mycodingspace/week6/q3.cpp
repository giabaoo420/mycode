/*3. Copy Constructor and Copy Assignment Operator
Duplicate the program and write Copy Constructor and Copy
Assignment Operator for the class Book. Test them in main().*/

#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    float price;

public:
    // Default Constructor
    Book(string t = "", string a = "", float p = 0.0) : title(t), author(a), price(p) {
        cout << "Default constructor called!" << endl;
    }

    // Copy Constructor
    Book(const Book &other) {
        cout << "Copy constructor called!" << endl;
        title = other.title;
        author = other.author;
        price = other.price;
    }

    // Copy Assignment Operator
    Book& operator=(const Book &other) {
        cout << "Copy assignment operator called!" << endl;

        // Check for self-assignment
        if (this == &other) {
            return *this;
        }

        // Copy data
        title = other.title;
        author = other.author;
        price = other.price;

        return *this;
    }

    // Destructor
    ~Book() {
        cout << "Destructor called!" << endl;
    }

    // Display method to print book details
    void display() const {
        cout << "Title: " << title << "\nAuthor: " << author << "\nPrice: $" << price << endl;
    }
};

int main() {
    // Create a book using the default constructor
    Book book1("1984", "George Orwell", 9.99);
    cout << "\nBook 1 details: " << endl;
    book1.display();

    // Test Copy Constructor
    Book book2 = book1; // This invokes the copy constructor
    cout << "\nBook 2 (copy of Book 1) details: " << endl;
    book2.display();

    // Modify book2 to show that it's a deep copy
    book2 = Book("Brave New World", "Aldous Huxley", 12.99);
    cout << "\nBook 2 modified details: " << endl;
    book2.display();

    // Test Copy Assignment Operator
    Book book3("Fahrenheit 451", "Ray Bradbury", 10.99);
    cout << "\nBook 3 details before assignment: " << endl;
    book3.display();

    book3 = book1; // This invokes the copy assignment operator
    cout << "\nBook 3 (after assigning from Book 1) details: " << endl;
    book3.display();

    return 0;
}