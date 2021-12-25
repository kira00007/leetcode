#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    map<char,int> priority = {
        {'+', 1},
        {'-', 1},
        {'*', 2},
        {'/', 2},
    };
    set<char> sign = {'+', '-', '*', '/'};
    int calculate(string s) {
        function<int(int,int,char)> operate = [](int num1, int num2, char op) {
			cout << "operating on " << num1 << op << num2 << '\n';
            int result;
            switch(op) {
                case '+':
                    result = num1 + num2;
                    break;
                case '-':
                    result = num1 - num2;
                    break;
                case '*':
                    result = num1 * num2;
                    break;
                case '/':
                    result = num1 / num2;
                    break;
                default:
                    cout << "invalid values\n";
                    break;
            };
            return result;
        };
        const int n = (int)s.size();
		stack<int> num_stack;
		stack<char> ope_stack;
        for(int i = 0; i < n; i++) {
            if(s[i] == ' ') continue;
            if(s[i] >= '0' && s[i] <= '9') {
                int num = 0;
				int j = i;
                for(; j < n && s[j] >= '0' && s[j] <= '9'; j++)
                    num = num * 10 + (s[j] - '0');
				num_stack.push(num);
				i = j - 1;
				cout << "num: " << num << '\n';
            }
            else {
				while(!ope_stack.empty() && priority[ope_stack.top()] >= priority[s[i]]) {
					char op = ope_stack.top();
					ope_stack.pop();
					int num2 = num_stack.top();
					num_stack.pop();
					int num1 = num_stack.top();
					num_stack.pop();
					num_stack.push(operate(num1, num2, op));
				}
                ope_stack.push(s[i]);
            }
        }
		while(!ope_stack.empty()) {
			char op = ope_stack.top();
			ope_stack.pop();
			int num2 = num_stack.top();
			num_stack.pop();
			int num1 = num_stack.top();
			num_stack.pop();
			num_stack.push(operate(num1, num2, op));
		}
		return num_stack.top();
    }
};

int main() {
	// string s = "3+2*2";
	string s = " 3+5 / 2 ";
	// string s = "3/2 ";
	cout << Solution().calculate(s);
	return 0;
}