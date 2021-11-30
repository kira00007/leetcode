#include <bits\stdc++.h>
using namespace std;

class Solution {
public:
    bool ob(char ch) {
        return (ch == '(' || ch == '[' || ch == '{');
    }
	map<char,char> cb = {
		{')', '('},
		{']', '['},
		{'}', '{'}
	};
    bool isValid(string s) {
        stack<char> st;
        for(char ch : s) {
            if(ob(ch)) st.push(ch);
            else {
                if(st.empty()) return false;
                if(st.top() == cb[ch]) st.pop();
                else return false;
            }
        }
        return st.empty();
    }
};

int main() {
	cout << Solution().isValid("()[]{}");
	return 0;
}