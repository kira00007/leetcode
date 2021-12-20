#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string str) {
        if(str.size() < 2) return 0;
        const int N = (int)str.size();
        int l = 0, r = N-1;
        while(l >= 0 && str[l] == ')') l++;
        while(r >= 0 && str[r] == '(') r--;
        if(l > r) return 0;
        vector<int> dp(N);
        int ans = 0;
        for(int i = r; i >= l; i--) {
            if(str[i] == '(') {
                bool found = false;
                for(int j = i + 1; j <= r;) {
                    if(str[j] == '(') {
                        if(dp[j] == 0) break;
                        dp[i] += dp[j];
                        j += dp[j];
                    }
                    else {
                        if(!found) {
                            found = true;
                            dp[i] = j - i + 1;
                        }
                        else break;
                        j++;
                    }
                }
                if(!found) dp[i] = 0;
                ans = max(ans, dp[i]);
            }
        }
        return ans;
    }
};

int main() {
	cout << Solution().longestValidParentheses("()()()") << '\n';
	cout << Solution().longestValidParentheses("()(()()") << '\n';
	cout << Solution().longestValidParentheses("(()") << '\n';
	cout << Solution().longestValidParentheses(")()())") << '\n';
	cout << Solution().longestValidParentheses("") << '\n';
	cout << Solution().longestValidParentheses("(") << '\n';
	cout << Solution().longestValidParentheses("((()))())") << '\n';
	cout << Solution().longestValidParentheses("()(())") << '\n';
	return 0;
}