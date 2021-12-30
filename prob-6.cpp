#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	string convert(string s, int n) {
		const int l = s.size();
		if(n == 1 || l <= n) return s;
		string ans;
		int inc = 2*n - 2;
		int st = 0;
		while(st < l) {
			ans.push_back(s[st]);
			st += inc;
		}
		for(int i = 1; i < (n-1); i++) {
			st = i;
			int inc1 = 2*(n-i-1);
			int inc2 = 2*i;
			bool swtch = false;
			while(st < l) {
				ans.push_back(s[st]);
				st += swtch ? inc2 : inc1;
				swtch = !swtch;
			}
		}
		st = n-1;
		// inc = 2*n - 2;
		while(st < l) {
			ans.push_back(s[st]);
			st += inc;
		}
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