#include <bits/stdc++.h>
using namespace std;

void print_vector(vector<int> &vec) {
	const int N = (int) vec.size();
	for(int i = 0; i < N; i++)
		cout << vec[i] << (i == N-1 ? '\n' : ' ');
	return;
};

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        const int N = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        set<int> s;
        set<vector<int>> ns;
        for(int i = 0; i < N-2; i++) {
            int lo = i + 1, hi = N - 1, ts = -nums[i];
            if(s.find(ts) != s.end()) continue;
            s.insert(ts);
            while(lo < hi) {
                if(nums[lo] + nums[hi] == ts) {
                    if(ns.find({nums[i], nums[lo], nums[hi]}) != ns.end()) {
                        lo++;
                        hi--;
                        continue;
                    };
                    ns.insert({nums[i], nums[lo], nums[hi]});
                    ans.push_back({nums[i], nums[lo], nums[hi]});
                    lo++;
                    hi--;
                }
                else if(nums[lo] + nums[hi] > ts)
                    hi--;
                else
                    lo++;
            }
        }
        return ans;
    }
};

int main() {
	// function<void(vector<int> &vec)> print_vector = [](vector<int> &vec) {
	// 	const int N = (int) vec.size();
	// 	for(int i = 0; i < N; i++)
	// 		cout << i << (i == N-1 ? '\n' : ' ');
	// 	return;
	// };
	vector<int> nums = {-1,0,1,2,-1,-4};
	vector<vector<int>> solution = Solution().threeSum(nums);
	for(vector<int> &vec : solution)
		print_vector(vec);
	return 0;
}