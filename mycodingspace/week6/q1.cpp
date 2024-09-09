/*Class Inheritance & Function Overriding
Create a hierarchy of classes as below, with attributes and methods are specified in each class.
Note: for each Tutor object, there are two versions of name attributes inherited from Student and
Staff classes. We should use only one version consistently, e.g. from the Student class by
Student::name. As a result, you can access name of a tutor with tutor.Student::name
For consultation() method, you only need to print out a message, e.g. “Doing consultation !”
a) Create constructors and destructors for all classes, both of which announce themselves to
console output. Verify that for a Tutor object, all three constructors and destructors are automatically
called. Explain the order in which the calls are made.
b) Write a method namely setName() for the class Tutor which accepts a string to set the Tutor’s
name.
c) Write a method namely toString() for all classes, which return all information as a string. Write two
external functions:
• showInfoStudent(Student &stu): print out all information of a Student or Tutor
• showInfoStaff(Staff &staff ): print out all information of a Staff or Tutor
Test all the methods written in question b and c in main().
*/


#include <iostream>
#include <string>
using namespace std;

// Base class: Student
class Student {
public:
    string name;
    int studentID;

    // Constructor
    Student(string n, int id) : name(n), studentID(id) {
        cout << "Student constructor called!" << endl;
    }

    // Destructor
    virtual ~Student() {
        cout << "Student destructor called!" << endl;
    }

    // toString method
    virtual string toString() const {
        return "Student Name: " + name + "\nStudent ID: " + to_string(studentID);
    }
};

// Base class: Staff
class Staff {
public:
    string name;
    int staffID;

    // Constructor
    Staff(string n, int id) : name(n), staffID(id) {
        cout << "Staff constructor called!" << endl;
    }

    // Destructor
    virtual ~Staff() {
        cout << "Staff destructor called!" << endl;
    }

    // toString method
    virtual string toString() const {
        return "Staff Name: " + name + "\nStaff ID: " + to_string(staffID);
    }
};

// Derived class: Tutor (inherits from both Student and Staff)
class Tutor : public Student, public Staff {
public:
    // Constructor
    Tutor(string studentName, int studentId, string staffName, int staffId)
        : Student(studentName, studentId), Staff(staffName, staffId) {
        cout << "Tutor constructor called!" << endl;
    }

    // Destructor
    ~Tutor() {
        cout << "Tutor destructor called!" << endl;
    }

    // Override toString method from both Student and Staff
    string toString() const override {
        // We use Student's name and studentID as per the instructions.
        return Student::toString() + "\nStaff Name: " + Staff::name + "\nStaff ID: " + to_string(staffID);
    }

    // Method for consultation
    void consultation() {
        cout << "Doing consultation!" << endl;
    }
};

// External function to show student info
void showInfoStudent(Student &stu) {
    cout << stu.toString() << endl;
}

// External function to show staff info
void showInfoStaff(Staff &staff) {
    cout << staff.toString() << endl;
}

int main() {
    // Create a Tutor object
    Tutor tutor("John Doe", 123, "Mr. John", 456);

    // Test consultation method
    tutor.consultation();

    // Display Student information using showInfoStudent()
    cout << "\nDisplaying information as Student:" << endl;
    showInfoStudent(tutor);

    // Display Staff information using showInfoStaff()
    cout << "\nDisplaying information as Staff:" << endl;
    showInfoStaff(tutor);

    return 0;
}