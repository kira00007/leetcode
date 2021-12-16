#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if(x == 1) return 1;
        if(n < 0) return 1 / (n&1 ? myPow(x, -(n/2) + 1)*myPow(x, -(n/2)) : myPow(x, -(n/2))*myPow(x, -(n/2)));
        if(n < 2) return n ? x : 1;
        if(x == 0) return 0;
        double result = 1;
        while(true) {
            if(n&1) result *= x;
            n >>= 1;
            if(n == 0) break;
            x *= x;
        }
        return result;
    }
};

int main() {
	std::cout << fixed << setprecision(19);
	std::cout << Solution().myPow(2.7, -15);
	return 0;
}