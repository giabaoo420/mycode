/*Defines a class namely Book with following private attributes and public methods (also
provide constructor for it):
o title (string)
o availableCopies (integer) which is the number of copies of the book which are
available to borrow.
o namesOfBorrowers (vector of strings) which are names of the book’s borrowers.
b) Define another class namely User with following attributes and public methods (also provide
constructor for it):
o name (string)
o borrowedBooks (vector of pointers of Book objects).
o bool doBorrow(Book &abook): to borrow a book from the library (must record the book
in borrowedBooks, borrower name in namesOfBorrowers of the book and reduce its
availableCopies).
o void doReturn(Book &abook): to return a book to the library (reverse the activities
above).
Note: Assume that each user can only borrow one copy of each book
Create a vector of three Book objects which are dynamically allocated.
Create two User objects and test all methods (with the created book objects)*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Book {
private:
    string title;
    int availableCopies;
    vector<string> namesOfBorrowers;

public:
    // Constructor
    Book(string t, int copies) : title(t), availableCopies(copies) {}

    // Method to get the book title
    string getTitle() const {
        return title;
    }

    // Method to get the number of available copies
    int getAvailableCopies() const {
        return availableCopies;
    }

    // Method to add a borrower
    bool addBorrower(const string& borrowerName) {
        if (availableCopies > 0) {
            namesOfBorrowers.push_back(borrowerName);
            availableCopies--;  // Decrease available copies
            return true;
        } else {
            cout << "No available copies of '" << title << "' to borrow!" << endl;
            return false;
        }
    }

    // Method to remove a borrower (return a book)
    void removeBorrower(const string& borrowerName) {
        for (auto it = namesOfBorrowers.begin(); it != namesOfBorrowers.end(); ++it) {
            if (*it == borrowerName) {
                namesOfBorrowers.erase(it);  // Remove the borrower
                availableCopies++;           // Increase available copies
                return;
            }
        }
        cout << "Borrower not found for this book." << endl;
    }

    // Method to print information about the book
    void printInfo() const {
        cout << "Title: " << title << ", Available Copies: " << availableCopies << endl;
        cout << "Borrowers: ";
        if (namesOfBorrowers.empty()) {
            cout << "None";
        } else {
            for (const auto& borrower : namesOfBorrowers) {
                cout << borrower << " ";
            }
        }
        cout << endl;
    }
};

class User {
protected:
    string name;
    vector<Book*> borrowedBooks;

public:
    // Constructor
    User(string n) : name(n) {}

    // Method to borrow a book
    virtual bool doBorrow(Book& abook) {
        // Check if the user has already borrowed this book
        for (const auto& book : borrowedBooks) {
            if (book->getTitle() == abook.getTitle()) {
                cout << name << " already borrowed '" << abook.getTitle() << "'." << endl;
                return false;
            }
        }

        // Try to borrow the book
        if (abook.addBorrower(name)) {
            borrowedBooks.push_back(&abook);  // Add book to borrowedBooks
            cout << name << " successfully borrowed '" << abook.getTitle() << "'." << endl;
            return true;
        }
        return false;
    }

    // Method to return a book
    void doReturn(Book& abook) {
        for (auto it = borrowedBooks.begin(); it != borrowedBooks.end(); ++it) {
            if ((*it)->getTitle() == abook.getTitle()) {
                abook.removeBorrower(name);  // Remove from the book's borrower list
                borrowedBooks.erase(it);     // Remove from borrowedBooks
                cout << name << " returned '" << abook.getTitle() << "'." << endl;
                return;
            }
        }
        cout << name << " has not borrowed '" << abook.getTitle() << "'." << endl;
    }

    // Method to display user's borrowed books
    void displayBorrowedBooks() const {
        cout << name << "'s borrowed books: ";
        if (borrowedBooks.empty()) {
            cout << "None";
        } else {
            for (const auto& book : borrowedBooks) {
                cout << book->getTitle() << " ";
            }
        }
        cout << endl;
    }
};

class SuperUser : public User {
public:
    // Constructor
    SuperUser(string n) : User(n) {}

    // Overridden method to borrow two books at once
    bool doBorrow(Book& book1, Book& book2) {
        bool borrowedBook1 = false;
        bool borrowedBook2 = false;

        // Check if SuperUser has already borrowed book1 or book2
        for (const auto& book : borrowedBooks) {
            if (book->getTitle() == book1.getTitle()) {
                cout << name << " already borrowed '" << book1.getTitle() << "'." << endl;
                borrowedBook1 = true;
            }
            if (book->getTitle() == book2.getTitle()) {
                cout << name << " already borrowed '" << book2.getTitle() << "'." << endl;
                borrowedBook2 = true;
            }
        }

        // Borrow book1 if not already borrowed
        if (!borrowedBook1 && book1.addBorrower(name)) {
            borrowedBooks.push_back(&book1);
            cout << name << " successfully borrowed '" << book1.getTitle() << "'." << endl;
            borrowedBook1 = true;
        }

        // Borrow book2 if not already borrowed
        if (!borrowedBook2 && book2.addBorrower(name)) {
            borrowedBooks.push_back(&book2);
            cout << name << " successfully borrowed '" << book2.getTitle() << "'." << endl;
            borrowedBook2 = true;
        }

        return borrowedBook1 && borrowedBook2;
    }
};

int main() {
    // Dynamically allocate three Book objects
    Book* book1 = new Book("The Great Gatsby", 3);
    Book* book2 = new Book("To Kill a Mockingbird", 2);
    Book* book3 = new Book("1984", 1);

    // Create a vector of pointers to these books
    vector<Book*> books = {book1, book2, book3};

    // Create a User and a SuperUser
    User user1("Alice");
    SuperUser superUser1("Bob");

    // Test borrowing books
    user1.doBorrow(*book1);  // Alice borrows "The Great Gatsby"
    superUser1.doBorrow(*book1, *book2);  // Bob borrows two books

    // Display borrowed books and book information
    user1.displayBorrowedBooks();
    superUser1.displayBorrowedBooks();

    book1->printInfo();
    book2->printInfo();

    // Clean up dynamically allocated memory
    delete book1;
    delete book2;
    delete book3;

    return 0;
}
