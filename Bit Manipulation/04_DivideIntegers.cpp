#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == divisor) return 1;
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        if (divisor == 1) return dividend;
        
        int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;
        
        long long n = abs((long long)dividend);
        long long d = abs((long long)divisor);
        int ans = 0;

        while (n >= d) {
            int p = 0;
            while (n >= (d << p)) p++;
            p--;
            n -= (d << p);
            ans += (1 << p);
        }

        return sign * ans;
    }
};

int main() {
    Solution sol;
    int dividend = -2147483648;
    int divisor = 2;
    cout << "Result: " << sol.divide(dividend, divisor) << endl;
    return 0;
}
