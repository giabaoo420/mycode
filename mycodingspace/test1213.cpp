#include <iostream>

#define SIZE 3

class Student {
private:
    std::string name;
    int scores[SIZE];

public:
    Student(std::string name, int scores[]) : name(name) {
        for (int i = 0; i < SIZE; i++) {
            this->scores[i] = scores[i]; // Using 'this->' to refer to the current object's scores
        }
    }

    bool operator > (const Student &stud) {
        int total1 = 0, total2 = 0;
        for (int i = 0; i < SIZE; i++) {
            total1 += this->scores[i]; // Using 'this->' to refer to the current object's scores
            total2 += stud.scores[i];  // Using 'stud.scores' to refer to the scores of the object passed as argument
        }
        return total1 > total2;
    }

    void display() const {
        std::cout << "Name: " << name << ", Scores: ";
        for (int i = 0; i < SIZE; i++) {
            std::cout << scores[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    int scores1[SIZE] = {85, 90, 88};
    int scores2[SIZE] = {80, 85, 89};

    Student student1("Alice", scores1);
    Student student2("Bob", scores2);

    student1.display(); // Outputs: Name: Alice, Scores: 85 90 88
    student2.display(); // Outputs: Name: Bob, Scores: 80 85 89

    if (student1 > student2) {
        std::cout << "Alice has higher total scores than Bob." << std::endl;
    } else {
        std::cout << "Bob has higher or equal total scores compared to Alice." << std::endl;
    }

    return 0;
}