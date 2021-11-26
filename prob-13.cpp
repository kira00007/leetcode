#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	map<char, int> rtn = {
		{'I', 1},
		{'V', 5},
		{'X', 10},
		{'L', 50},
		{'C', 100},
		{'D', 500},
		{'M', 1000}

	};
	int romanToInt(string s) {
		const int N = (int) s.size();
		int ans = 0;
		function<bool(int)> sub = [&](int i) {
			return ((s[i] == 'V' || s[i] == 'X') && s[i - 1] == 'I') || ((s[i] == 'L' || s[i] == 'C') && s[i - 1] == 'X') || ((s[i] == 'D' || s[i] == 'M') && s[i - 1] == 'C');
		};
		for(int i = N-1; i >= 0; i--) {
			ans += rtn[s[i]];
			if(i && sub(i)) {
				ans -= rtn[s[i - 1]];
				i--;
			}
		}
		return ans;
	}
};

int main() {
	string s = "XXX";
	cout << Solution().romanToInt(s) << '\n';
	return 0;
}