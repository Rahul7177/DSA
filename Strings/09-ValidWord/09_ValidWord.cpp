// A word is considered valid if:

// It contains a minimum of 3 characters.
// It contains only digits (0-9), and English letters (uppercase and lowercase).
// It includes at least one vowel.
// It includes at least one consonant.
// You are given a string word.

// Return true if word is valid, otherwise, return false.

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isVowel(char ch) {
        ch = tolower(ch);
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    bool isValid(string word) {
        if (word.length() < 3) return false;
        bool hasVowel = false;
        bool hasConsonant = false;
        for (char ch : word) {
            if (!isalnum(ch)) return false; // must be letter or digit
            if (isalpha(ch)) {
                if (isVowel(ch)) {
                    hasVowel = true;
                } else {
                    hasConsonant = true;
                }
            }
        }
        return hasVowel && hasConsonant;
    }
};

int main() {
    Solution sol;
    string word1 = "apple";
    string word2 = "sky";
    string word3 = "123";
    string word4 = "a1";
    string word5 = "aei";

    cout << (sol.isValid(word1) ? "true" : "false") << endl;
    cout << (sol.isValid(word2) ? "true" : "false") << endl;
    cout << (sol.isValid(word3) ? "true" : "false") << endl;
    cout << (sol.isValid(word4) ? "true" : "false") << endl;
    cout << (sol.isValid(word5) ? "true" : "false") << endl;

    return 0;
}
