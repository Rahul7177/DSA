// 796. Rotate String

// Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.
// A shift on s consists of moving the leftmost character of s to the rightmost position.
// For example, if s = "abcde", then it will be "bcdea" after one shift.
 
// Example 1:
// Input: s = "abcde", goal = "cdeab"
// Output: true

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        return s.size() == goal.size() && (s + s).find(goal) < s.size();
    }
};

int main() {
    Solution sol;
    string s1 = "abcde";
    string g1 = "cdeab";
    string s2 = "abcde";
    string g2 = "abced";
    bool result1 = sol.rotateString(s1, g1);
    bool result2 = sol.rotateString(s2, g2);
    cout << (result1 ? "true" : "false") << endl;
    cout << (result2 ? "true" : "false") << endl;
    return 0;
}
