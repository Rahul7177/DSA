// URL: https://leetcode.com/problems/number-of-1-bits/description/

// 191. Number of 1 Bits

// Given a positive integer n, write a function that returns the number of set bits in its binary representation (also known as the Hamming weight).

// Example 1:
// Input: n = 11
// Output: 3

// Explanation:
// The input binary string 1011 has a total of three set bits.

// Example 2:
// Input: n = 128
// Output: 1

// Explanation:
// The input binary string 10000000 has a total of one set bit.

// Example 3:
// Input: n = 2147483645
// Output: 30

// Explanation:
// The input binary string 1111111111111111111111111111101 has a total of thirty set bits.

// Constraints:
// 	1 <= n <= 231 - 1

#include <iostream>
using namespace std;

class Solution {
public:
  int hammingWeight(uint32_t n) {
    int res = 0;
    for (int i = 0; i < 32; i++) {
      if ((n >> i) & 1) {
        res += 1;
      }
    }
    return res;    
  }
};

int main() {
  Solution sol;
  uint32_t n = 11; // Binary: 00000000000000000000000000001011
  cout << "Hamming Weight of " << n << " = " << sol.hammingWeight(n) << endl;

  return 0;
}
