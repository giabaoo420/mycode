// From the Student class in question 2, add another private string attribute namely password.
// Write a method for the class namely changePwd() to allow people to change their password as
// below and test it in main function.
// a. If there is no existing password (no name.dat file, whereas name is student name, or no
// content in the file), allow them to provide value for the password. Save it into the file
// (name.dat).
// b. If there is an existing password, ask them to enter their previous password to check. If it is
// matched, save the new password into their file.


#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Student {
    public:
    string name;
    int score;
    
    Student() : name(""), score(0) {}
    Student(string n, int s) {
        name = n;   
        score = s;
        password = "";
    }

    void changePwd() {
        string newpassword;
        ifstream file(name + ".dat");

        if (!file.is_open()) {
            cout <<  "enter a new password: ";
            cin >> newpassword;
        } else {
            string savedpassword;
            file >> savedpassword;
            file.close();
            
            string oldpassword ;
            cout << "enter old password: ";
            cin >> oldpassword;

            if (oldpassword == savedpassword) {
               cout << "enter new password: ";
               cin >> newpassword;
            } else {
                cout << "incorrect password." << endl;
                return;
            }
        }

        ofstream outFile(name + ".dat");
        outFile << newpassword;
        outFile.close();
        cout << "password changed succesfully" << endl;
    }

    private:
    string password;
};

int main() {
    Student student1("bao", 100);
    Student student2("bob", 0);

    cout << "student 1 name = " << student1.name << ", score = " << student1.score << endl;
    cout << "student 2 name = " << student2.name << ", score = " << student2.score << endl;

    Student student[3] = {{"Charlie", 78}, {"David", 95}, {"Eve", 88}};

    Student studenthighestscore = student[0];
    for(int i =  1; i < 3; i++) {
        if (student[i].score > studenthighestscore.score) {
            studenthighestscore = student[i];
        }
    }
    cout << "student who got the highest score: " << studenthighestscore.name << ", score: " << studenthighestscore.score << endl;

    student[0].changePwd();

    return 0;
}