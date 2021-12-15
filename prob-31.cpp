#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
		next_permutation(nums.begin(), nums.end());
		for(int i = 0; i < (int)nums.size(); i++) {
			std::cout << nums[i] << (i == (int)nums.size() - 1 ? '\n' : ' ');
		}
    }
};

int main() {
	vector<int> nums = {3, 2, 1};
	Solution().nextPermutation(nums);
	return 0;
}