// Define a class namely Cat with public attributes are name (string), age (int).
// Define another class namely Person with public attributes are cat (Cat class) and name (string).
// Each class must have their own constructors.
// a. Make an array of three persons, and initialize values for them.
// b. Print out the information of the person who has the cat with the highest age (also print out
// information of that cat).


#include <iostream>
#include <string>

class Cat {
public:
    std::string name;
    int age;

    Cat(std::string n, int a) : name(n), age(a) {}
};

class Person {
public:
    Cat cat;
    std::string name;

    Person(Cat c, std::string n) : cat(c), name(n) {}
};

int main() {
    Person people[3] = {
        Person(Cat("Whiskers", 5), "Alice"),
        Person(Cat("Mittens", 3), "Bob"),
        Person(Cat("Fluffy", 7), "Charlie")
    };

    Person oldestOwner = people[0];
    for (int i = 1; i < 3; ++i) {
        if (people[i].cat.age > oldestOwner.cat.age) {
            oldestOwner = people[i];
        }
    }

    std::cout << "Owner Name: " << oldestOwner.name << std::endl;
    std::cout << "Cat Name: " << oldestOwner.cat.name << std::endl;
    std::cout << "Cat Age: " << oldestOwner.cat.age << std::endl;

    return 0;
}