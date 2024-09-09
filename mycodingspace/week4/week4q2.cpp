// Define a class namely BankAcc with two public attributes are name (string) and amount (float).
// a) Write a class constructor to initialize those attributes. Test it in main() by creating three bank
// account objects and use the constructor to initialize data for them. Then print out all
// information.
// b) Write a public method for the class namely withdraw(float num) which allow a user to
// withdraw money from his/her account:
// • If current amount >= num: subtract amount value by num
// • If current amount < num: return an error code, and print out an error message.
// Test the method inside the main function.
// c) Modify the program above so that it can save all data (one line for each account) into a file,
// whose filename is given from the command line argument (at the end of the program). If
// the user does not give the command line argument, don’t save data.
// Example Run: ./a.exe data_file.dat



#include <iostream>
#include <fstream>
#include <string>

class BankAcc {
public:
    std::string name;
    float amount;

    BankAcc(const std::string& n, float a) : name(n), amount(a) {}

    void displayInfo() {
        std::cout << "Name: " << name << ", Amount: " << amount << std::endl;
    }
    
    void withdraw(float num) {
    if (amount >= num) {
        amount -= num;
    } else {
        std::cerr << "Error: Insufficient funds for withdrawal." << std::endl;
    }
}
};
int main(int argc, char* argv[]) {
    BankAcc acc1("John", 1000.0);
    BankAcc acc2("Alice", 500.0);
    BankAcc acc3("Bob", 1500.0);

    acc1.withdraw(200.0);
    acc2.withdraw(600.0);

    if (argc > 1) {
        std::ofstream file(argv[1]);
        file << acc1.name << " " << acc1.amount << std::endl;
        file << acc2.name << " " << acc2.amount << std::endl;
        file << acc3.name << " " << acc3.amount << std::endl;
        file.close();
    }

    return 0;
}