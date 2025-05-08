#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s;

    s.push(5);
    s.push(15);
    s.push(25);
    cout << "Elements after pushing 5, 15, 25:" << endl;

    stack<int> temp = s; 
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    s.pop();
    cout << "Elements after popping one element:" << endl;
    temp = s;
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    cout << "Top element: " << s.top() << endl;

    cout << "Is stack empty? " << (s.empty() ? "Yes" : "No") << endl;

    cout << "Stack size: " << s.size() << endl;

    return 0;
}
