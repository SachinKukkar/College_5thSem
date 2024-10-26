#include <iostream>
#include <string>
using namespace std;

// Recursive function to find the length of the Longest Common Subsequence
int lcsRecursive(const string& text1, const string& text2, int m, int n, string& lcs) {
    // Base case: if either string is empty, the LCS length is 0
    if (m == 0 || n == 0) {
        return 0;
    }

    // If the last characters match, move to the next characters in both strings
    if (text1[m - 1] == text2[n - 1]) {
        lcs = text1[m - 1] + lcs;  // Prepend the matched character to LCS
        return 1 + lcsRecursive(text1, text2, m - 1, n - 1, lcs);
    } else {
        // If the last characters do not match, find the maximum LCS length by
        // excluding the last character of one of the strings
        string lcs1 = lcs, lcs2 = lcs; // Copy current LCS
        int len1 = lcsRecursive(text1, text2, m - 1, n, lcs1);
        int len2 = lcsRecursive(text1, text2, m, n - 1, lcs2);
        
        // Store the longer LCS in lcs
        lcs = (len1 > len2) ? lcs1 : lcs2;
        return max(len1, len2);
    }
}

int main() {
    string text1, text2;

    cout << "Enter first string: ";
    cin >> text1;
    cout << "Enter second string: ";
    cin >> text2;

    string lcs; // To store the longest common subsequence
    int lcsLength = lcsRecursive(text1, text2, text1.length(), text2.length(), lcs);
    
    cout << "Length of Longest Common Subsequence: " << lcsLength << endl;
    cout << "Longest Common Subsequence: " << lcs << endl;

    return 0;
}
