#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> ans;
    void func(int o, int c, int n, string s) {
        if((int)s.size() == 2*n) {
            ans.push_back(s);
            return;
        }
        if(o) {
            s.push_back('(');
            func(o-1, c+1, n, s);
            s.pop_back();
        }
        if(c) {
            s.push_back(')');
            func(o, c-1, n, s);
        }
    }
    vector<string> generateParenthesis(int n) {
        ans.clear();
        string s;
        func(n, 0, n, s);
        return ans;
    }
};