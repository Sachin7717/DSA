#include <iostream>

using namespace std;

class MyClass {
private:
    int value;
    string name;

public:

    MyClass() : value(0), name("Default") {
        cout << "Default constructor called." << endl;
    }

  
    MyClass(int v, string n) : value(v), name(n) {
        cout << "Parameter constructor called." << endl;
    }

    
    MyClass( MyClass &obj) : value(obj.value), name(obj.name) {
        cout << "Copy constructor called." << endl;
    }

    void display() {
        cout << "Value: " << value << ", Name: " << name << endl;
    }
};


int main() {
   
    MyClass obj1;
    obj1.display();
    

   
    MyClass obj2(42, "Example");
    obj2.display();

    
    MyClass obj3 = obj2;
    obj3.display();

    return 0;
    
}
