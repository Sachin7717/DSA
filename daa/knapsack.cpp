#include <iostream>
#include <algorithm>

using namespace std;

// Function to solve the 0/1 Knapsack problem
int knapsack(int weights[], int values[], int n, int capacity) {
    // Create a 2D array to store the maximum value that can be obtained for each capacity
    int dp[n + 1][capacity + 1];

    // Initialize the first row and first column of the dp table to 0
    for (int i = 0; i <= n; ++i) {
        for (int w = 0; w <= capacity; ++w) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
        }
    }

    // Build the table in a bottom-up manner
    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= capacity; ++w) {
            // If the current item's weight is more than the current capacity,
            // then the maximum value that can be obtained is same as the
            // maximum value obtained without including this item
            if (weights[i - 1] > w) {
                dp[i][w] = dp[i - 1][w];
            } else {
                // Otherwise, we have two choices:
                // 1. Include the current item
                // 2. Exclude the current item
                // We choose the maximum of the two
                dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]]);
            }
        }
    }

    // The maximum value will be stored at dp[n][capacity]
    return dp[n][capacity];
}

int main() {
    int weights[] = {2, 3, 4, 5};
    int values[] = {3, 9, 5, 6};
    int capacity = 7;
    int n = sizeof(values) / sizeof(values[0]);

    int max_value = knapsack(weights, values, n, capacity);
    cout << "Maximum value that can be obtained: " << max_value << endl;

    return 0;
}
