#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to find the length of the longest common subsequence
int lcs(string X, string Y) {
    int m = X.size();
    int n = Y.size();
    
    // Create a 2D table to store lengths of LCS for different substrings
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Build the dp table in bottom-up fashion
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // dp[m][n] contains the length of LCS for X[0..m-1], Y[0..n-1]
    return dp[m][n];
}

// Function to print the Longest Common Subsequence
void printLCS(string X, string Y) {
    int m = X.size();
    int n = Y.size();

    // Create the dp table
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Build the dp table in bottom-up fashion
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Reconstruct the LCS by backtracking the dp table
    int i = m, j = n;
    string lcsStr = "";

    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcsStr = X[i - 1] + lcsStr; // Add character to LCS
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    cout << "LCS: " << lcsStr << endl;
}

int main() {
    string X, Y;

    // Input two strings
    cout << "Enter first string: ";
    cin >> X;

    cout << "Enter second string: ";
    cin >> Y;

    // Function call to calculate LCS length
    cout << "Length of LCS: " << lcs(X, Y) << endl;

    // Function call to print the LCS
    printLCS(X, Y);

    return 0;
}
