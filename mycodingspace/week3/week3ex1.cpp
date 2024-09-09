// Write a program to provide a menu for user to:
// a. Input a password (which is a string). Save it into a file namely "pwd.dat".
// b. Read the stored password from the file. Print it out to the console.
// Example Run:
// Password management program:
// 1. Save your password
// 2. Read your password
// Your choice: 1
// Enter the password: abc123
// Saved to the file!



#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    int choice;
    string password;

    cout << "Password Management Program: \n1. Save your password\n2. Read your password\n";
    cin >> choice;

    if (choice == 1)
    {
        cout << "enter your password: ";
        cin.ignore();
        getline(cin, password);
        ofstream file("pwd.dat");
        if (file.is_open())
        {
            file << password;
            cout << "saved to the file" << endl;
            file.close();
        }
        else
        {
            cerr << "unable to open file" << endl;
        }
    }
    else if (choice == 2)
    {
        ifstream file("pwd.dat");
        if (file.is_open())
        {
            getline(file, password);
            cout << "stored password: " << password << endl;
            file.close();
        }
        else
        {
            cerr << "unable to open file." << endl;
        }
    }
    else
    {
        cout << "invalid choice";
    }
    return 0;
}