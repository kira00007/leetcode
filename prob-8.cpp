#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isdigit(char ch) {
        return (ch > 47 && ch < 58);
    }
    int myAtoi(string s) {
        const int N = (int) s.size();
        int it = 0, en = N;
        for(; it < N; it++) {
            if(isdigit(s[it]) || s[it] == '+' || s[it] == '-') break;
            if(s[it] != ' ') return 0;
        }
        bool sgn = true;
        if(s[it] == '+') it++;
        else if(s[it] == '-') it++, sgn = false;
        // if(!isdigit(s[it])) return 0; // maybe I can remove this line
        for(int i = it; i < N; i++) {
            //find en in what should be a pure number
            if(!isdigit(s[i])) {
                en = i;
                break;
            }
        }
        for(; it < en; it++) if(s[it] != '0') break;
        if((en-it) > 10) return sgn ? INT_MAX : INT_MIN;
        if((en-it) == 10 && (s[it] - '0') > 2) return sgn ? INT_MAX : INT_MIN;
        long long ans = 0;
        for(; it < en; it++) {
            if(sgn)
                ans = ans * 10 + (s[it] - '0');
            else
                ans = ans * 10 - (s[it] - '0');
        }
        if(ans > INT_MAX || ans < INT_MIN)
            return sgn ? INT_MAX : INT_MIN;
        return (int) ans;
    }
};

int main() {
	cout << Solution().myAtoi("2147483646") << '\n';
	return 0;
}