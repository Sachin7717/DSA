#include <iostream>
#include <vector>

using namespace std;

void findSubset(vector<int>& S, int target, vector<int>& current, int index, int sum) {
    if (sum == target) {
        // If the current subset sums up to the target, print it
        cout << "Solution: {";
        for (int i = 0; i < current.size(); ++i) {
            cout << current[i];
            if (i < current.size() - 1)
                cout << ", ";
        }
        cout << "}" << endl;
        return;
    }

    // Backtracking
    for (int i = index; i < S.size(); ++i) {
        if (sum + S[i] <= target) {
            current.push_back(S[i]);
            findSubset(S, target, current, i + 1, sum + S[i]);
            current.pop_back();
        }
    }
}

void subsetSum() {
    int n;
    cout << "Enter the number of elements in the set: ";
    cin >> n;
    vector<int> S(n);
    cout << "Enter the elements of the set:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> S[i];
    }
    int target;
    cout << "Enter the target value: ";
    cin >> target;

    vector<int> current;
    findSubset(S, target, current, 0, 0);
}

int main() {
    subsetSum();
    return 0;
}
