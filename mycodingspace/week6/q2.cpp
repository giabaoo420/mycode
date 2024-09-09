/*Vector of Objects & Data Saving/Loading
a) Reuse the class Student in question 1, write another class namely SchoolSystem with an attribute
namely students which is a vector of Student objects. Write two methods for this class as below
• addStudent(): prompt user to input name and student ID for a student and add to students list.
• removeStudent(): prompt user to input student ID and remove the corresponding student from
students list.
b) In main() function, provide a menu as below for user. Save all information of students into a file
namely students.dat at the end, and reload all data back at the beginning.
School Management System
1. View all students
2. Add Student
3. Remove Student
4. Exit
Enter Your Choice:………*/

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

// Reusing the Student class from the previous task
class Student {
public:
    string name;
    int studentID;

    // Constructor
    Student(string n = "", int id = 0) : name(n), studentID(id) {}

    // toString method
    string toString() const {
        return "Student Name: " + name + "\nStudent ID: " + to_string(studentID);
    }
};

// Class for managing the list of students
class SchoolSystem {
private:
    vector<Student> students;

public:
    // Method to add a student to the list
    void addStudent() {
        string name;
        int studentID;

        // Prompt user for input
        cout << "Enter Student Name: ";
        cin.ignore(); // To handle leftover newline from previous inputs
        getline(cin, name);
        cout << "Enter Student ID: ";
        cin >> studentID;

        // Create and add the new student
        Student newStudent(name, studentID);
        students.push_back(newStudent);
        cout << "Student added successfully!" << endl;
    }

    // Method to remove a student by their student ID
    void removeStudent() {
        int studentID;
        cout << "Enter Student ID to remove: ";
        cin >> studentID;

        // Search and remove the student by ID
        bool found = false;
        for (auto it = students.begin(); it != students.end(); ++it) {
            if (it->studentID == studentID) {
                students.erase(it);
                found = true;
                cout << "Student removed successfully!" << endl;
                break;
            }
        }

        if (!found) {
            cout << "Student not found!" << endl;
        }
    }

    // Method to display all students
    void viewAllStudents() {
        if (students.empty()) {
            cout << "No students in the list." << endl;
        } else {
            for (const auto& student : students) {
                cout << student.toString() << endl;
                cout << "------------------------" << endl;
            }
        }
    }

    // Method to save all students to a file
    void saveToFile() {
        ofstream outFile("students.dat", ios::binary);
        if (!outFile) {
            cerr << "Error opening file for writing!" << endl;
            return;
        }

        size_t size = students.size();
        outFile.write(reinterpret_cast<const char*>(&size), sizeof(size));

        for (const auto& student : students) {
            size_t nameLen = student.name.size();
            outFile.write(reinterpret_cast<const char*>(&nameLen), sizeof(nameLen));
            outFile.write(student.name.c_str(), nameLen);
            outFile.write(reinterpret_cast<const char*>(&student.studentID), sizeof(student.studentID));
        }

        outFile.close();
        cout << "Student data saved to students.dat." << endl;
    }

    // Method to load students from a file
    void loadFromFile() {
        ifstream inFile("students.dat", ios::binary);
        if (!inFile) {
            cout << "No previous data found, starting fresh." << endl;
            return;
        }

        size_t size;
        inFile.read(reinterpret_cast<char*>(&size), sizeof(size));

        students.clear();
        for (size_t i = 0; i < size; ++i) {
            size_t nameLen;
            inFile.read(reinterpret_cast<char*>(&nameLen), sizeof(nameLen));

            string name(nameLen, ' ');
            inFile.read(&name[0], nameLen);

            int studentID;
            inFile.read(reinterpret_cast<char*>(&studentID), sizeof(studentID));

            students.push_back(Student(name, studentID));
        }

        inFile.close();
        cout << "Student data loaded from students.dat." << endl;
    }
};

int main() {
    SchoolSystem schoolSystem;
    schoolSystem.loadFromFile(); // Load data at the start

    int choice;
    do {
        cout << "\nSchool Management System" << endl;
        cout << "1. View all students" << endl;
        cout << "2. Add Student" << endl;
        cout << "3. Remove Student" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                schoolSystem.viewAllStudents();
                break;
            case 2:
                schoolSystem.addStudent();
                break;
            case 3:
                schoolSystem.removeStudent();
                break;
            case 4:
                schoolSystem.saveToFile(); // Save data before exiting
                cout << "Exiting... Data saved." << endl;
                break;
            default:
                cout << "Invalid choice! Please choose again." << endl;
                break;
        }
    } while (choice != 4);

    return 0;
}