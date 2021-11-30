#include <bits\stdc++.h>
using namespace std;

class Solution {
public:
    bool ob(char ch) {
        return (ch == '(' || ch == '[' || ch == '{');
    }
    stack<char> st;
	map<char,char> cb = {
		{')', '('},
		{']', '['},
		{'}', '{'}
	};
    bool isValid(string s) {
        for(char ch : s) {
            if(ob(ch)) st.push(ch);
            else {
                if(!st.empty() && st.top() == cb[ch]) st.pop();
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