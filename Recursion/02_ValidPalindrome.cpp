#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool solve(const string& s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }

    bool isPalindrome(string s) {
        string str = "";
        for (char i : s) {
            if (isalnum(i))
                str += tolower(i);
        }
        return solve(str, 0, str.length() - 1);
    }
};

int main() {
    Solution sol;
    string input1 = "A man, a plan, a canal: Panama";
    string input2 = "race a car";
    bool result1 = sol.isPalindrome(input1);
    bool result2 = sol.isPalindrome(input2);
    cout << (result1 ? "true" : "false") << endl;
    cout << (result2 ? "true" : "false") << endl;
    return 0;
}
