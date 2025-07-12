// 451. Sort Characters By Frequency

// Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.
// Return the sorted string. If there are multiple answers, return any of them.

// Example 1:
// Input: s = "tree"
// Output: "eert"

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for (auto i : s) {
            mp[i]++;
        }
        vector<pair<char, int>> freq(mp.begin(), mp.end());
        sort(freq.begin(), freq.end(),
             [](const pair<char, int>& a, const pair<char, int>& b) {
                 return a.second > b.second;
             });
        string res = "";
        for (auto& [key, value] : freq) {
            res.append(value, key);
        }
        return res;
    }
};

int main() {
    Solution sol;
    string input1 = "tree";
    string input2 = "cccaaa";
    string input3 = "Aabb";
    string result1 = sol.frequencySort(input1);
    string result2 = sol.frequencySort(input2);
    string result3 = sol.frequencySort(input3);
    cout << result1 << endl;
    cout << result2 << endl;
    cout << result3 << endl;
    return 0;
}
