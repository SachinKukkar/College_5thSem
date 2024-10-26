#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

// Function prototype for printing the optimal parenthesization
void printOptimalParenthesization(const vector<vector<int>>& s, int i, int j);

// Function to perform matrix chain multiplication
int matrixChainMultiplication(const vector<int>& p) {
    int n = p.size() - 1; // Number of matrices
    vector<vector<int>> m(n, vector<int>(n, 0)); // Minimum cost matrix
    vector<vector<int>> s(n, vector<int>(n, 0)); // Split point matrix

    // m[i][i] is zero, as the cost of multiplying one matrix is zero
    for (int length = 2; length <= n; length++) {
        for (int i = 0; i < n - length + 1; i++) {
            int j = i + length - 1;
            m[i][j] = INT_MAX; // Initialize to a large value

            // Try different positions to split the product
            for (int k = i; k < j; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i] * p[k + 1] * p[j + 1];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k; // Store the split point
                }
            }
        }
    }

    // Print the split points for matrix multiplication
    cout << "Optimal parenthesization is: ";
    printOptimalParenthesization(s, 0, n - 1);
    cout << endl;

    return m[0][n - 1]; // Return the minimum cost
}

// Function to print the optimal parenthesization
void printOptimalParenthesization(const vector<vector<int>>& s, int i, int j) {
    if (i == j) {
        cout << "A" << i + 1; // Naming the matrices as A1, A2, ...
    } else {
        cout << "(";
        printOptimalParenthesization(s, i, s[i][j]);
        printOptimalParenthesization(s, s[i][j] + 1, j);
        cout << ")";
    }
}

int main() {
    // Dimensions of matrices
    // Example: A1 is 10x30, A2 is 30x5, A3 is 5x60
    vector<int> dimensions = {6,12,6,42,7,5}; // p = {10, 30, 5, 60} for A1, A2, A3

    int minCost = matrixChainMultiplication(dimensions);
    cout << "Minimum number of multiplications is: " << minCost << endl;

    return 0;
}
