// 14. Longest Common Prefix

// Write a function to find the longest common prefix string amongst an array of strings.

// If there is no common prefix, return an empty string "".

// Example 1:

// Input: strs = ["flower","flow","flight"]
// Output: "fl"

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty())
            return "";
        string prefix = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            string current = strs[i];
            int j = 0;
            while (j < prefix.size() && j < current.size() && prefix[j] == current[j]) {
                j++;
            }
            prefix = prefix.substr(0, j);
            if (prefix == "")
                return "";
        }
        return prefix;
    }
};

int main() {
    Solution sol;
    vector<string> input1 = {"flower","flow","flight"};
    vector<string> input2 = {"dog","racecar","car"};
    string result1 = sol.longestCommonPrefix(input1);
    string result2 = sol.longestCommonPrefix(input2);
    cout << result1 << endl;
    cout << result2 << endl;
    return 0;
}
