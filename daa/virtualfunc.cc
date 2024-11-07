#include <iostream>
#include <string>
using namespace std;

class Student {
protected:
    string name;
    int id;

public:
    virtual void getData() {
        cout << "Enter student name: ";
        cin >> name;
        cout << "Enter student ID: ";
        cin >> id;
    }

    virtual void displayData() {
        cout << "Student Name: " << name << endl;
        cout << "Student ID: " << id << endl;
    }
};

class UndergraduateStudent : public Student {
private:
    string branch;

public:
    void getData() {
        Student::getData();
        cout << "Enter student's branch: ";
        cin >> branch;
    }

    void displayData() {
        Student::displayData();
        cout << "Student's branch: " << branch << endl;
    }
};




int main() {
    UndergraduateStudent student1;
    cout << "Enter details for Undergraduate Student:" << endl;
    student1.getData();
    

    cout << "\nDisplaying Undergraduate Student data:" << endl;
    student1.displayData();
    

    

    return 0;
}