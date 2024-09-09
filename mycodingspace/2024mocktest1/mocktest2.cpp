#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>

using namespace std;

class Student {
    private:
        string name = "";
        int scores[3] = {0};
    public:
    Student(){};

    Student(string name, int scores[]) {
        this->name = name;
        for (int i = 0; i < 3; i++) {
            this->scores[i] = scores[i];
        }
    }
    void inputData() {
        cout << "please enter name of student" << endl;
        getline(cin, name);
        cout << "please enter 3 scores for " << name << ": ";
        for (int i = 0; i < 3; i++) {
            cin >> scores[i];
        }
        cin.ignore();
    }
    void setName(string name) {
         this->name = name;
    }

    void setScore (int scores[]) {
        for (int i = 0; i < 3; i++) {
            this->scores[i] = scores[i];
        }
    }

    void showInfo() {
        cout << "name: " << name << endl;
        for (int i = 0; i < 3; i++) {
            cout << "score " << i+1 << ": " << scores[i] << endl;
        }
    }
    bool operator > (Student &stud) {
        int total1 = 0, total2 = 0;
        float ave1, ave2;
        for (int i = 0; i < 3; i++) {
            total1 += this->scores[i];
            total2 += stud.scores[i];
        }
        ave1 = (float)total1/3.0;
        ave2 = (float)total2/3.0;

        if (ave1 > ave2) return true;
        else return false;
    }
    friend istream& operator >> (istream &in, Student &stud);
    friend ostream& operator << (ostream *out, Student &stud);
    friend Student operator + (int n, Student &stud);
};

istream& operator >> (istream &in, Student &stud) {
    stud.inputData();
    /*cout << "please enter name of student: ";
    getline(in, stud.name);
    cout << "please enter 3 scores for " << stud.name << ": ";
    for (int i = 0; i < 3; i++) {
        in >> stud.scores[i];
    }
    return in;*/
    return in;
}
ostream& operator << (ostream &out, Student &stud) {
    stud.showInfo();
    /*out << "name: " << stud.name << endl;
    for (int i = 0; i < 3; i++) {
        out << "score " << i + 1 << ": " << stud.scores[i] << endl;
    } */
    return out;
}

Student operator + (int n, Student &stud) {
    Student temp;
    string sname;
    cout << "please enter a name: ";
    getline(cin, sname);
    if(sname == stud.name) {
      temp.name = stud.name;
      for (int i = 0; i < 3; i++) {            
        temp.scores[i] = n + stud.scores[i];
        }
    }
    return temp;
}
int main() {
    Student students[10];
    std::ifstream file("data.txt");
    if (file.is_open()) {
        for (int i = 0; i < 10; ++i) {
            file >> students[i];
        }
        file.close();
    }

    Student highestAvgStudent = students[0];
    for (int i = 1; i < 10; ++i) {
        if (students[i] > highestAvgStudent) {
            highestAvgStudent = students[i];
        }
    }

    std::cout << "Student with the highest average score:\n";
    std::cout << highestAvgStudent;

    return 0;
}