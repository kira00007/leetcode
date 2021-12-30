#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	string convert(string s, int n) {
		const int l = s.size();
		if(n == 1 || l <= n) return s;
		string ans;
        for(int st = 0; st < l; st += (2*n-2))
            ans.push_back(s[st]);
		for(int i = 1; i < (n-1); i++) {
            for(int st = i; st < l; st += 2*i) {
                ans.push_back(s[st]);
                st += 2*(n-i-1);
                if(st < l) ans.push_back(s[st]);
            }
		}
        for(int st = n-1; st < l; st += (2*n-2))
            ans.push_back(s[st]);
		return ans;
	}
};

int main() {
	vector<pair<string, int>> test_cases = {
		{"PAYPALISHIRING", 3},
		{"PAYPALISHIRING", 4},
		{"PAYPALISHIRING", 5},
		{"PAYPALISHIRING", 1},
		{"P", 10},
	};
	Solution sol;
	for(pair<string, int> test_case : test_cases) {
		cout << sol.convert(test_case.first, test_case.second) << '\n';
	}
	return 0;
}