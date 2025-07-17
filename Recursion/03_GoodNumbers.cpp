// URL: https://leetcode.com/problems/count-good-numbers/description/

// 1922. Count Good Numbers

// A digit string is good if the digits (0-indexed) at even indices are even and the digits at odd indices are prime (2, 3, 5, or 7).

// 	For example, "2582" is good because the digits (2 and 8) at even positions are even and the digits (5 and 2) at odd positions are prime. However, "3245" is not good because 3 is at an even index but is not even.

// Given an integer n, return the total number of good digit strings of length n. Since the answer may be large, return it modulo 109 + 7.

// A digit string is a string consisting of digits 0 through 9 that may contain leading zeros.

// Example 1:
// Input: n = 1
// Output: 5
// Explanation: The good numbers of length 1 are "0", "2", "4", "6", "8".

// Example 2:
// Input: n = 4
// Output: 400

// Example 3:
// Input: n = 50
// Output: 564908303

// Constraints:
// 	1 <= n <= 1015

#include <iostream>
using namespace std;

class Solution {
public:
    const long long MOD = 1e9 + 7;


        // long long modPow(long long base, long long exp) {
    //     long long result = 1;
    //     base %= MOD;
    //     while (exp > 0) {
    //         if (exp % 2 == 1) {
    //             result = (result * base) % MOD;
    //         }
    //         base = (base * base) % MOD;
    //         exp /= 2;
    //     }
    //     return result;
    // }

    // Recursive way
    long long modPow(long long base, long long exp) {
        if (exp == 0)
            return 1;
        if (exp % 2 == 0) {
            long long half = modPow((base * base) % MOD, exp / 2);
            return half;
        } else {
            return (base * modPow(base, exp - 1)) % MOD;
        }
    }

    int countGoodNumbers(long long n) {
        long long evenPos = (n + 1) / 2;
        long long oddPos = n / 2;

        long long evenPart = modPow(5, evenPos);
        long long oddPart = modPow(4, oddPos);

        return (evenPart * oddPart) % MOD;
    }
};

int main() {
    Solution sol;
    cout << sol.countGoodNumbers(1) << endl;       // Output: 5
    cout << sol.countGoodNumbers(4) << endl;       // Output: 400
    cout << sol.countGoodNumbers(50) << endl;      // Large input
    return 0;
}
