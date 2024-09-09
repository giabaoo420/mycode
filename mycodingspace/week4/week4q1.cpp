// Write a program that defines a class called ComplNum for complex numbers with two private
// attributes are real and imag (double).
// a) Provide two overloaded versions for the constructor: a default constructor, and another one
// with two parameters to initialize attributes (require to use this keyword).
// b) Overload - and -- operators to use for ComplNum objects as below:
// • object – object
// • object – double
// • double – object
// • object--;
// • --object;
// Test all cases above in main() functions.
// c) Write a non-member friend function which accepts an ComplNum object and return its
// absolute value. Test it in main() function.



#include <iostream>
#include <cmath>

class ComplNum {
private:
    double real;
    double imag;

public:
    // Default constructor
    ComplNum() : real(0), imag(0) {}

    // Parameterized constructor
    ComplNum(double r, double i) : real(r), imag(i) {}

    // Overload the - operator for object - object
    ComplNum operator-(const ComplNum& other) const {
        return ComplNum(real - other.real, imag - other.imag);
    }

    // Overload the - operator for object - double
    ComplNum operator-(double value) const {
        return ComplNum(real - value, imag);
    }

    // Overload the - operator for double - object
    friend ComplNum operator-(double value, const ComplNum& c) {
        return ComplNum(value - c.real, -c.imag);
    }

    // Overload the -- operator (postfix)
    ComplNum operator--(int) {
        ComplNum temp = *this; // Store current value
        real--; // Decrement real part
        imag--; // Decrement imaginary part
        return temp; // Return old value
    }

    // Overload the -- operator (prefix)
    ComplNum& operator--() {
        real--; // Decrement real part
        imag--; // Decrement imaginary part
        return *this; // Return current object
    }

    // Friend function to calculate the absolute value
    friend double absolute(const ComplNum& c) {
        return std::sqrt(c.real * c.real + c.imag * c.imag);
    }

    // Function to display the complex number
    void display() const {
        std::cout << real << (imag >= 0 ? "+" : "") << imag << "i" << std::endl;
    }
};

int main() {
    // Testing the ComplNum class
    ComplNum c1(3, 4); // 3 + 4i
    ComplNum c2(1, 2); // 1 + 2i

    std::cout << "c1: ";
    c1.display();
    std::cout << "c2: ";
    c2.display();

    // Test object - object
    ComplNum c3 = c1 - c2;
    std::cout << "c1 - c2: ";
    c3.display();

    // Test object - double
    ComplNum c4 = c1 - 2.0;
    std::cout << "c1 - 2.0: ";
    c4.display();

    // Test double - object
    ComplNum c5 = 5.0 - c1;
    std::cout << "5.0 - c1: ";
    c5.display();

    // Test object-- (postfix)
    ComplNum c6 = c1--;
    std::cout << "c1--: ";
    c6.display();
    std::cout << "After c1--, c1: ";
    c1.display();

    // Test --object (prefix)
    ComplNum c7 = --c1;
    std::cout << "--c1: ";
    c7.display();
    std::cout << "After --c1, c1: ";
    c1.display();

    // Test absolute value function
    double absValue = absolute(c1);
    std::cout << "Absolute value of c1: " << absValue << std::endl;

    return 0;
}