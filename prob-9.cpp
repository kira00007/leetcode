#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool isPalindrome(int x) {
        if(x < 0) return false;
        long long y = 0, temp = x;
        while(temp) {
            y = y*10 + temp%10;
            temp /= 10;
        }
        return y == x;
    }
};

int main() {
	std::cout << Solution().isPalindrome(121) << '\n';
	return 0;
}