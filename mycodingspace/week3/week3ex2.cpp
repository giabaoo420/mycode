// Define a class namely Student with attributes are name (string) and score (integer). Both of them
// are public.
// a. Write a constructor for the class to initialize attributes’ values.
// b. Create two student objects and initialize values for them using class constructor. Print out
// all information of the two students.
// c. Create an array of three students and initialize values for all of them using class
// constructor. Print out information of the student with highest score.
// Additional: modify the program so that score is private, and make a method namely get_score()
// to provide reading access to it.



#include <iostream>
#include <string>
using namespace std;

class Student {
    public:
    string name;
    int score;

    Student(string n, int s) {
        name = n;   
        score = s;
    }
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

    return 0;
}
