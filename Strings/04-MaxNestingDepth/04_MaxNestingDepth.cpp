// Leetcode : 1614 - Maximum Nesting Depth of the Parentheses

// Given a valid parentheses string s, return the nesting depth of s. The nesting depth is the maximum number of nested parentheses.


// Example 1:

// Input: s = "(1+(2*3)+((8)/4))+1"

// Output: 3

// Explanation:

// Digit 8 is inside of 3 nested parentheses in the string.

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int depth = 0, maxDepth = 0;
        for (char ch : s) {
            if (ch == '(') {
                depth++;
                maxDepth = max(maxDepth, depth);
            } else if (ch == ')') {
                depth--;
            }
        }
        return maxDepth;
    }
};

int main() {
    Solution sol;
    string input1 = "(1+(2*3)+((8)/4))+1";
    string input2 = "(1)+((2))+(((3)))";
    int result1 = sol.maxDepth(input1);
    int result2 = sol.maxDepth(input2);
    cout << result1 << endl;
    cout << result2 << endl;
    return 0;
}
