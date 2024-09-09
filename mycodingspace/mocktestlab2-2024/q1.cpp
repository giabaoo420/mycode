/*Question 1 (8 pts)
Define a class namely Employee with two attributes are name (string) and salary (double). Define
subclass namely Manager (derives from the Employee class) which has an additional attribute is
allowance (double).
For each class, provide a constructor to initialize all attributes, and a showInfo() method to print
out all information.
a) Create and initialize an object for each class in main() then print out all information.
b) Create an array of 05 manager objects using dynamic memory allocation. Calculate and
print out the average of their total income. Note: total income = salary + allowance*/

#include <iostream>
#include <iomanip>
#include <vector>

class Employee {
protected:
    std::string name;
    double salary;

public:
    Employee(std::string name, double salary) {
        this->name = name;
        this->salary = salary;
    }

    void showInfo() {
        std::cout << "Employee Name: " << name << std::endl;
        std::cout << "Salary: $" << std::fixed << std::setprecision(2) << salary << std::endl;
    }
};

class Manager : public Employee {
private:
    double allowance;

public:
    Manager(std::string name, double salary, double allowance) : Employee(name, salary) {
        this->allowance = allowance;
    }

    double totalIncome() {
        return salary + allowance;
    }

    void showInfo() {
        Employee::showInfo();
        std::cout << "Allowance: $" << std::fixed << std::setprecision(2) << allowance << std::endl;
        std::cout << "Total Income: $" << std::fixed << std::setprecision(2) << totalIncome() << std::endl;
    }
};

int main() {
    // a) Create and initialize an object for each class
    Employee emp("John Doe", 50000);
    emp.showInfo();
    std::cout << std::endl;

    Manager mgr("Bao", 1000000, 600000);
    mgr.showInfo();
    std::cout << std::endl;

    // b) Create an array of 5 manager objects using dynamic memory allocation
    std::vector<Manager*> managers = {
        new Manager("Manager 1", 80000, 20000),
        new Manager("Manager 2", 85000, 25000),
        new Manager("Manager 3", 90000, 30000),
        new Manager("Manager 4", 95000, 35000),
        new Manager("Manager 5", 100000, 40000)
    };

    // Calculate the average total income
    double totalIncome = 0;
    for (const auto& manager : managers) {
        totalIncome += manager->totalIncome();
    }
    double averageIncome = totalIncome / managers.size();

    std::cout << "Average Total Income of Managers: $" << std::fixed << std::setprecision(2) << averageIncome << std::endl;

    // Clean up dynamically allocated memory
    for (auto manager : managers) {
        delete manager;
    }

    return 0;
}