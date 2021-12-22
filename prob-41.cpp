#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& a) {
        int n = (int)a.size();
        for(int &x : a) if(x <= 0 || x > n) x = 1e9;
        for(int i = 0; i < n; i++) {
            int idx = abs(a[i]);
            if((idx > 0 && idx <= n) && a[idx - 1] > 0) a[idx - 1] = -a[idx - 1];
        }
        for(int i = 0; i < n; i++) if(a[i] > 0) return i + 1;
        return n + 1;
    }
};

int main() {
	vector<int> a = {3,4,-1,1};
	// vector<int> a = {7,8,9,11,12};
	cout << Solution().firstMissingPositive(a) << '\n';
	return 0;
}