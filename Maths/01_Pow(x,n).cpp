#include <iostream>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        long long N = n; 
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }

        double result = 1.0;
        while (N > 0) {
            if (N % 2 == 1) {
                result *= x;
            }
            x *= x;
            N /= 2;
        }

        return result;
    }
};

int main() {
    Solution sol;
    
    // Test cases
    cout << sol.myPow(2.0, 10) << endl;   // 1024.0
    cout << sol.myPow(2.0, -2) << endl;   // 0.25
    cout << sol.myPow(3.0, 0) << endl;    // 1.0
    cout << sol.myPow(5.0, 1) << endl;    // 5.0

    return 0;
}
