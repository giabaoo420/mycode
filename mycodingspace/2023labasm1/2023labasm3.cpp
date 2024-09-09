/*Defines a class namely Book with following private attributes
o title (string)
o price (integer)
o availableCopies (integer) which is the number of book copies available to borrow.
o borrowerNames[10] (array of 10 strings) which are names of borrowers (write “NA” if
elements are not names of borrowers).
Write constructor for it to initialize the attributes, and three methods as below:
bool borrow(string borrowerName): to borrow a book from the library. Return true if
succeed and false if fail (e.g. no available copies).
o void return(string borrowerName): to return a book to the library and remove the
borrowerName from the list.*
b) Define another class namely User with two attributes are name (string), Book*
borrowedBooks[5] (array of Book object pointers). Provide constructor for it, and two methods
as below:
• bool doBorrow(Book *abook): borrow a book from the library (hint: must call borrow ()
method of Book object).
• void doReturn(Book *abook): to return a book to the library (hint: must call return ()
method of Book object).
c) Overload the operators so that we can do following operations
• User >> Book : Return all copies of the book from the user
• Book++ : Increase one available copy of the book in the library.
• int n + Book: increase the price of the book by n.
Test all functions and operators in main. You should have appropriate message when printing to
screen.
*/

#include <iostream>
#include <string>

using namespace std;

class Book {
private:
    string title;
    int price;
    int availableCopies;
    string borrowerNames[10];

public:
    Book(string title, int price, int copies) {
        this->title = title;
        this->price = price;
        this->availableCopies = copies;
        for (int i = 0; i < 10; i++) {
            borrowerNames[i] = "NA";
        }
    }

    bool borrow(string borrowerName) {
        if (availableCopies > 0) {
            for (int i = 0; i < 10; i++) {
                if (borrowerNames[i] == "NA") {
                    borrowerNames[i] = borrowerName;
                    availableCopies--;
                    return true;
                }
            }
        }
        return false;
    }

    void returnBook(string borrowerName) {
        for (int i = 0; i < 10; i++) {
            if (borrowerNames[i] == borrowerName) {
                borrowerNames[i] = "NA";
                availableCopies++;
                break;
            }
        }
    }

    friend ostream& operator<<(ostream& os, const Book& book);
    friend Book& operator++(Book& book);
    friend Book operator+(int n, Book& book);
    friend istream& operator>>(istream& is, Book& book);
};

class User {
private:
    string name;
    Book* borrowedBooks[5];

public:
    User(string name) {
        this->name = name;
        for (int i = 0; i < 5; i++) {
            borrowedBooks[i] = nullptr;
        }
    }

    bool doBorrow(Book* book) {
        for (int i = 0; i < 5; i++) {
            if (borrowedBooks[i] == nullptr) {
                if (book->borrow(name)) {
                    borrowedBooks[i] = book;
                    return true;
                }
                return false;
            }
        }
        return false;
    }

    void doReturn(Book* book) {
        for (int i = 0; i < 5; i++) {
            if (borrowedBooks[i] == book) {
                book->returnBook(name);
                borrowedBooks[i] = nullptr;
                break;
            }
        }
    }

    friend istream& operator>>(istream& is, User& user);
};

ostream& operator<<(ostream& os, const Book& book) {
    os << "Title: " << book.title << ", Price: " << book.price << ", Available Copies: " << book.availableCopies << endl;
    os << "Borrowers: ";
    for (int i = 0; i < 10; i++) {
        if (book.borrowerNames[i] != "NA") {
            os << book.borrowerNames[i] << " ";
        }
    }
    os << endl;
    return os;
}

Book& operator++(Book& book) {
    book.availableCopies++;
    return book;
}

Book operator+(int n, Book& book) {
    book.price += n;
    return book;
}

istream& operator>>(istream& is, Book& book) {
    for (int i = 0; i < 10; i++) {
        if (book.borrowerNames[i] != "NA") {
            book.returnBook(book.borrowerNames[i]);
        }
    }
    return is;
}

istream& operator>>(istream& is, User& user) {
    for (int i = 0; i < 5; i++) {
        if (user.borrowedBooks[i] != nullptr) {
            user.borrowedBooks[i]->returnBook(user.name);
            user.borrowedBooks[i] = nullptr;
        }
    }
    return is;
}

int main() {
    Book book1("Book 1", 10, 3);
    User user1("John");

    cout << book1;

    if (user1.doBorrow(&book1)) {
        cout << "Book borrowed successfully!" << endl;
    } else {
        cout << "Failed to borrow the book." << endl;
    }

    cout << book1;

    user1.doReturn(&book1);

    cout << book1;

    ++book1;

    cout << book1;

    5 + book1;

    cout << book1;

    return 0;
}