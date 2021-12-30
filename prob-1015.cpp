#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k == 1) return 1;
        set<int> seen = {1};
        int curr = 1;
        for(int i = 2; i < 100000; i++) {
            curr = curr*10 + 1;
            int remainder = curr%k;
            if(remainder) {
                if(seen.find(remainder) != seen.end()) return -1;
                else seen.insert(remainder);
            }
            else
                return i;
            curr = remainder;
        }
        return -1;
    }
};

int main() {
	vector<int> test_cases = {
		1,
		2,
		3,
		4,
		5,
		6,
		7,
		8,
		9,
		10,
		11,
		12,
		13,
		14,
		15,
		16,
		17,
		18,
		19,
		20,
	};
	Solution sol;
	for(int tc : test_cases) {
		cout << sol.smallestRepunitDivByK(tc) << '\n';
	}
	return 0;
}