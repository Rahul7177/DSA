#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int count[26] = {0};

        for (char x : s) {
            count[x - 'a']++;
        }

        for (char x : t) {
            count[x - 'a']--;
        }

        for (int val : count) {
            if (val != 0) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    string s = "anagram";
    string t = "nagaram";

    Solution sol;
    bool result = sol.isAnagram(s, t);

    if (result)
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}
