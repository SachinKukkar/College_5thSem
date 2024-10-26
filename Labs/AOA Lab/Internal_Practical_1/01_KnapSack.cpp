#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to calculate the maximum value in the knapsack
int knapsack(int capacity, vector<int>& weights, vector<int>& values, int n) {
    // Create a 2D array to store the maximum value at each n and capacity
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    // Build the dp array
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            // If the weight of the current item is less than or equal to the current capacity
            if (weights[i - 1] <= w) {
                // Choose the maximum between including the item or excluding it
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            } else {
                // If the weight is more than the capacity, don't include the item
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // The maximum value is stored in dp[n][capacity]
    return dp[n][capacity];
}

int main() {
    int n, capacity;
    
    cout << "Enter number of items: ";
    cin >> n;
    cout << "Enter capacity of knapsack: ";
    cin >> capacity;

    vector<int> weights(n);
    vector<int> values(n);

    cout << "Enter weights and values for each item (weight value):\n";
    for (int i = 0; i < n; i++) {
        cin >> weights[i] >> values[i];
    }

    int maxValue = knapsack(capacity, weights, values, n);
    cout << "Maximum value in the knapsack = " << maxValue << endl;

    return 0;
}
