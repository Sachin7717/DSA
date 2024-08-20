#include <iostream>
using namespace std;

class Student {
private:
    int rollNumber;
    string name;
    int age;
    float marks;

public:

    Student(int r, string n, int a, float m) : rollNumber(r), name(n), age(a), marks(m) {}

    void displayDetails() {
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Marks: " << marks << endl;

    }
    
};
 
int main() {

    Student student1(1, "Batman", 20, 85.5);
    Student student2(2, "Superman", 21, 90);
    Student student3(3, "Spiderman", 18, 89);

    student1.displayDetails();
    student2.displayDetails();
    student3.displayDetails();

    return 0;
}
