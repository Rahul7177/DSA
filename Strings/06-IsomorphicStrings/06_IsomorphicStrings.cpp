// Leetcoe : 205 - Isomorphic Strings

// Given two strings s and t, determine if they are isomorphic.
// Two strings s and t are isomorphic if the characters in s can be replaced to get t.
// All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

// Example 1:
// Input: s = "egg", t = "add"
// Output: true

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) return false;
        int s_map[256] = {0};
        int t_map[256] = {0};
        for (int i = 0; i < s.length(); i++) {
            if (s_map[s[i]] != t_map[t[i]])
                return false;
            s_map[s[i]] = i + 1;
            t_map[t[i]] = i + 1;
        }
        return true;
    }
};

int main() {
    Solution sol;
    string s1 = "egg";
    string t1 = "add";
    string s2 = "foo";
    string t2 = "bar";
    string s3 = "paper";
    string t3 = "title";
    bool result1 = sol.isIsomorphic(s1, t1);
    bool result2 = sol.isIsomorphic(s2, t2);
    bool result3 = sol.isIsomorphic(s3, t3);
    cout << (result1 ? "true" : "false") << endl;
    cout << (result2 ? "true" : "false") << endl;
    cout << (result3 ? "true" : "false") << endl;
    return 0;
}
