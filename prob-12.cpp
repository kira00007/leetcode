#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	map<int, string> ones = {
		{1, "I"},
		{2, "II"},
		{3, "III"},
		{4, "IV"},
		{5, "V"},
		{6, "VI"},
		{7, "VII"},
		{8, "VIII"},
		{9, "IX"},
	};
	map<int, string> tens = {
		{1, "X"},
		{2, "XX"},
		{3, "XXX"},
		{4, "XL"},
		{5, "L"},
		{6, "LX"},
		{7, "LXX"},
		{8, "LXXX"},
		{9, "XC"},
	};
	map<int, string> huns = {
		{1, "C"},
		{2, "CC"},
		{3, "CCC"},
		{4, "CD"},
		{5, "D"},
		{6, "DC"},
		{7, "DCC"},
		{8, "DCCC"},
		{9, "CM"},
	};
	map<int, string> thous = {
		{1, "M"},
		{2, "MM"},
		{3, "MMM"},
	};
    string intToRoman(int num) {
		string ans;
		int ch = 1000;
		while(ch) {
			if(ch == 1000)
				ans += thous[num/1000], num %= 1000;
			else if(ch == 100)
				ans += huns[num/100], num %= 100;
			else if(ch == 10)
				ans += tens[num/10], num %= 10;
			else if(ch == 1)
				ans += ones[num];
			// cout << ch << ' ' << num << ' ' << ans << '\n';
			ch /= 10;
		}
		return ans;
    }
};

int main() {
	vector<int> test_cases = {
		3,
		58,
		1994,
	};
	Solution sol;
	for(int tc : test_cases) {
		cout << sol.intToRoman(tc) << '\n';
	}
	return 0;
}