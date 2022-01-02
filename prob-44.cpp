#include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:
// 	bool newfunc(string s, string p) {
// 		if(s.empty()) {
// 			if(p.empty()) return true;
// 			for(char ch : p) if(ch != '*') return false;
// 			return true;
// 		}
// 		if(p.empty()) return false;
// 		if(p[0] == '*') return(isMatch(s.substr(1, (int)s.size()-1), p.substr(1, (int)p.size()-1)) || isMatch(s.substr(1, (int)s.size()-1), p) || isMatch(s, p.substr(1, (int)p.size()-1)));
// 		if(p[0] == '?') return (isMatch(s.substr(1, (int)s.size()-1), p.substr(1, (int)p.size()-1)));
// 		return (s[0]==p[0] ? isMatch(s.substr(1, (int)s.size()-1), p.substr(1, (int)p.size()-1)) : false);
// 	}
//     bool isMatch(string s, string tp) {
// 		string p;
// 		for(int i = 0; i < (int)tp.size(); i++) {
// 			if(tp[i] != '*') p.push_back(tp[i]);
// 			else if(i == (int)tp.size()-1 || tp[i] != tp[i+1]) p.push_back('*');
// 		}
// 		return newfunc(s, p);
//     }
// };

class Solution {
public:
	bool newfunc(string s, string p) {
		int l1 = (int)s.size();
		int l2 = (int)p.size();
		if(l1 == 0) return (p == "*" || p.empty());
        if(l2 == 0) return false;
		bool dp[l1][l2];
		memset(dp, 0, sizeof(dp));
		for(int i = l1 - 1; i >= 0; i--) for(int j = l2 - 1; j >= 0; j--) {
			if(p[j] == '*') {
				if(j == l2-1) dp[i][j] = true;
				else if(i == l1-1) dp[i][j] = dp[i][j + 1];
				else dp[i][j] = (dp[i][j + 1] || dp[i + 1][j] || dp[i + 1][j + 1]);
			}
			else if(p[j] == '?') {
				if(i == l1-1 && j == l2-1) dp[i][j] = true;
				else if(j == l2-1 && i < l1-1) dp[i][j] = false;
				else if(j < l2-1 && i == l1-1) {
					if(j == l2-2 && p[l2-1] == '*') dp[i][j] = true;
					else dp[i][j] = false;
				}
				else dp[i][j] = dp[i + 1][j + 1];
			}
			else {
				if(i == l1-1 && j == l2-1) dp[i][j] = (s[i] == p[j]);
				else if(j == l2-1 && i < l1-1) dp[i][j] = false;
				else if(j < l2-1 && i == l1-1) {
					if(j == l2-2 && p[l2-1] == '*' && (s[i] == p[j])) dp[i][j] = true;
					else dp[i][j] = false;
				}
				else dp[i][j] = (s[i] == p[j]) && dp[i + 1][j + 1];
			}
		}
		return dp[0][0];
	}
    bool isMatch(string s, string tp) {
		string p;
		for(int i = 0; i < (int)tp.size(); i++) {
			if(tp[i] != '*') p.push_back(tp[i]);
			else if(i == (int)tp.size()-1 || tp[i] != tp[i+1]) p.push_back('*');
		}
		return newfunc(s, p);
    }
};

int main() {
	vector<pair<string,string>> test_cases = {
		{"abcd", "acb?"},
		{"abcd", "abc?"},
		{"abcd", "a??d"},
		{"abcd", "a?cd"},
		{"abcd", "a??c"},
		{"abcd", "???d"},
		{"abcd", "?b?d"},
		{"abcd", "a?"},
		{"aa", "a"},
		{"aa", "*"},
		{"cb", "?a"},
		{"abcadb", "*?a*b"},
		{"abcadb", "*?a*b*?"},
		{"adceb", "*a*b"},
		{"", "******"},
		{"babaaababaabababbbbbbaabaabbabababbaababbaaabbbaaab", "***bba**a*bbba**aab**b"},
		{"bbbbbbbabbaabbabbbbaaabbabbabaaabbababbbabbbabaaabaab", "b*b*ab**ba*b**b***bba"},
		{"abbaabbbbababaababababbabbbaaaabbbbaaabbbabaabbbbbabbbbabbabbaaabaaaabbbbbbaaabbabbbbababbbaaabbabbabb", "***b**a*a*b***b*a*b*bbb**baa*bba**b**bb***b*a*aab*a**"},
	};
	Solution sol;
	for(pair<string,string> test_case : test_cases) {
		cout << test_case.first << ' ' << test_case.second << ": ";
		cout << (sol.isMatch(test_case.first, test_case.second) ? "true\n" : "false\n");
	}
}

/*
"abcd"
"acb?"
"abcd"
"abc?"
"abcd"
"a??d"
"abcd"
"a?cd"
"abcd"
"a??c"
"abcd"
"???d"
"abcd"
"?b?d"
"abcd"
"a?"
"aa"
"a"
"aa"
"*"
"cb"
"?a"
"abcadb"
"*?a*b"
"abcadb"
"*?a*b*?"
"adceb"
"*a*b"
""
"******"
"babaaababaabababbbbbbaabaabbabababbaababbaaabbbaaab"
"***bba**a*bbba**aab**b"
"bbbbbbbabbaabbabbbbaaabbabbabaaabbababbbabbbabaaabaab"
"b*b*ab**ba*b**b***bba"
"abbaabbbbababaababababbabbbaaaabbbbaaabbbabaabbbbbabbbbabbabbaaabaaaabbbbbbaaabbabbbbababbbaaabbabbabb"
"***b**a*a*b***b*a*b*bbb**baa*bba**b**bb***b*a*aab*a**"
*/