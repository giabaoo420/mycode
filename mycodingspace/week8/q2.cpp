/*Exercise 2:
You are involved in development of a software for school management. The
following details are as follows:
Each staff are managed by his/her name and department. He/she can belong to
one or none of department. It is possible for a staff to join or leave a department in
some cases (e.g. leave or change to another department).
The system allows to manage each department by its name and location, each of
which needs to have at least one staff.
For the academic department, its number of courses will be recorded. Whereas,
for non-academic department, the number of services is monitored.
Nouns: class or attribute. Class are nouns that you have something belong to (and
you need to manage it). Attribute is a single value.
Verbs: method
a) Draw the class diagram for the above system.
Only make the noun become class if you want to manage it (otherwise, just make it as
attribute).
Class: staff attributes: name, department. methods: joinDept(), leaveDept().
Class: department attributes: name, location, staff_list
Child class of department:
Academic department: attribute: number of courses
Non-cademic department: attribute: number of services
b) Write a C++ program to implement the above system (test all attributes and
methods in main() function).
Nouns: class/ attribute
Verbs: method*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>  // For std::find

using namespace std;

class Department;  // Forward declaration

class Staff {
private:
    string name;
    Department* department;

public:
    Staff(const string& name) : name(name), department(nullptr) {}

    void joinDept(Department* dept);
    void leaveDept();
    
    string getName() const { return name; }
    Department* getDepartment() const { return department; }
};

class Department {
protected:
    string name;
    string location;
    vector<Staff*> staff_list;

public:
    Department(const string& name, const string& location)
        : name(name), location(location) {}

    virtual ~Department() {
        // Clear the staff list without calling leaveDept()
        staff_list.clear();
    }

    void addStaff(Staff* staff) {
        staff_list.push_back(staff);
    }

    void removeStaff(Staff* staff) {
        auto it = find(staff_list.begin(), staff_list.end(), staff);
        if (it != staff_list.end()) {
            staff_list.erase(it);
        }
    }

    string getName() const { return name; }
    string getLocation() const { return location; }
    const vector<Staff*>& getStaffList() const { return staff_list; }
};

class AcademicDepartment : public Department {
private:
    int numberOfCourses;

public:
    AcademicDepartment(const string& name, const string& location, int numCourses)
        : Department(name, location), numberOfCourses(numCourses) {}

    int getNumberOfCourses() const { return numberOfCourses; }
    void setNumberOfCourses(int numCourses) { numberOfCourses = numCourses; }
};

class NonAcademicDepartment : public Department {
private:
    int numberOfServices;

public:
    NonAcademicDepartment(const string& name, const string& location, int numServices)
        : Department(name, location), numberOfServices(numServices) {}

    int getNumberOfServices() const { return numberOfServices; }
    void setNumberOfServices(int numServices) { numberOfServices = numServices; }
};

void Staff::joinDept(Department* dept) {
    if (department) {
        department->removeStaff(this);
    }
    department = dept;
    if (dept) {
        dept->addStaff(this);
    }
}

void Staff::leaveDept() {
    if (department) {
        department->removeStaff(this);
        department = nullptr;
    }
}

int main() {
    AcademicDepartment mathDept("Mathematics", "Building A", 10);
    NonAcademicDepartment adminDept("Administration", "Building B", 5);

    Staff alice("Alice");
    Staff bob("Bob");

    // Test joining and leaving departments
    alice.joinDept(&mathDept);
    bob.joinDept(&adminDept);

    // Print department details
    cout << "Academic Department: " << mathDept.getName() << ", Location: " << mathDept.getLocation() << ", Number of Courses: " << mathDept.getNumberOfCourses() << endl;
    cout << "Non-Academic Department: " << adminDept.getName() << ", Location: " << adminDept.getLocation() << ", Number of Services: " << adminDept.getNumberOfServices() << endl;

    cout << "Staff in Mathematics Department: " << endl;
    for (const Staff* staff : mathDept.getStaffList()) {
        cout << "- " << staff->getName() << endl;
    }

    cout << "Staff in Administration Department: " << endl;
    for (const Staff* staff : adminDept.getStaffList()) {
        cout << "- " << staff->getName() << endl;
    }

    // Test leaving department
    alice.leaveDept();
    cout << "After Alice leaves Mathematics Department:" << endl;
    cout << "Staff in Mathematics Department: " << endl;
    for (const Staff* staff : mathDept.getStaffList()) {
        cout << "- " << staff->getName() << endl;
    }

    return 0;
}