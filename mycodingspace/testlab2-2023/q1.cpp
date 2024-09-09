/*Write a C++ program to ask the user to input studentName and studentID. Save it to the file
namely studentName.dat
Sample Run:
Input your student name: An Nguyen
Input your student id: s4010128
Your data is saved !*/


#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string studentName;
    std::string studentID;

    // Prompt user for student name
    std::cout << "Input your student name: ";
    std::getline(std::cin, studentName); // Use getline to allow spaces in the name

    // Prompt user for student ID
    std::cout << "Input your student id: ";
    std::getline(std::cin, studentID); // Use getline to allow spaces in the ID if needed

    // Open a file in write mode
    std::ofstream outFile("studentName.dat");
    
    // Check if the file opened successfully
    if (!outFile) {
        std::cerr << "Error opening file!" << std::endl;
        return 1; // Exit with an error code
    }

    // Write the student name and ID to the file
    outFile << "Student Name: " << studentName << std::endl;
    outFile << "Student ID: " << studentID << std::endl;

    // Close the file
    outFile.close();

    // Notify the user that the data is saved
    std::cout << "Your data is saved." << std::endl;

    return 0; // Exit successfully
}