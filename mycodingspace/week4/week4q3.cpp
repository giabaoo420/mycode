// Write a program that ask the user to input two strings str1, str2 which may contain whitespace
// characters from the console. //”hello how are you?”
// a) Reserve str1 and print it out.
// For example, "Good Morning” → “gninroM dooG”
// b) Convert all characters of str2 from lowercase to uppercase and vice versa, and print it out.
// For example, "Hello World” → “hELLO wORLD”
// Do the above tasks with character array (C-type string) and C++ string class, then convert to the
// other.

#include <iostream>
#include <cstring>
#include <algorithm>

int main() {
    char str1[100], str2[100];
    
    // Input two strings
    std::cout << "Enter the first string: ";
    std::cin.getline(str1, 100);
    
    std::cout << "Enter the second string: ";
    std::cin.getline(str2, 100);
    
    // Reverse str1
    std::reverse(str1, str1 + strlen(str1));
    std::cout << "Reversed str1: " << str1 << std::endl;
    
    // Toggle case of str2
    for (int i = 0; i < strlen(str2); i++) {
        if (islower(str2[i])) {
            str2[i] = toupper(str2[i]);
        } else if (isupper(str2[i])) {
            str2[i] = tolower(str2[i]);
        }
    }
    std::cout << "Toggled case str2: " << str2 << std::endl;
    
    // Convert C-style strings to C++ strings
    std::string cppStr1(str1);
    std::string cppStr2(str2);
    
    // Perform operations on C++ strings if needed
    
    return 0;
}