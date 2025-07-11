// Leetcode : 1903 Largest Odd Number in String

// You are given a string num, representing a large integer. Return the largest-valued odd integer (as a string) that is a non-empty substring of num, or an empty string "" if no odd integer exists.

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string largestOddNumber(string num) {
        int k = -1;
        for (int i = num.size() - 1; i >= 0; i--) {
            int digit = num[i] - '0'; 
            if (digit % 2 != 0) {
                k = i;
                break;
            }
        }
        return k == -1 ? "" : num.substr(0, k + 1);
    }
};

int main() {
    Solution sol;
    string input1 = "52";
    string input2 = "4206";
    string input3 = "35427";
    string result1 = sol.largestOddNumber(input1);
    string result2 = sol.largestOddNumber(input2);
    string result3 = sol.largestOddNumber(input3);
    cout << result1 << endl;
    cout << result2 << endl;
    cout << result3 << endl;
    return 0;
}
