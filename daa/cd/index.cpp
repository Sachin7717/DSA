#include <iostream>
#include <string>
using namespace std;
enum State {q0, q1, q2};

bool isAccepted(string input) {
    State currentState = q0;
    for (char ch : input) {
        switch (currentState) {
            case q0:
                currentState = (ch == '0') ? q0 : q1;
                break;
            case q1:
                currentState = (ch == '0') ? q2 : q0;
                break;
            case q2:
                currentState = (ch == '0') ? q1 : q2;
                break;
            default:
                break;
        }
    }
    return (currentState == q0);
}

int main() {
    string input;
    cout << "Enter a binary string: ";
    cin >> input;
    if (isAccepted(input)) {
        cout << "Accepted: The string is divisble by 3." << endl;
    } else {
        cout << "Rejected: The string is not divisible by 3." << endl;
    }
    return 0;
}
