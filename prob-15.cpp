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
		map<int, int> mp;
        const int N = (int) nums.size();
        for(int i = 0; i < N; i++) mp[nums[i]] = i;
        set<vector<int>> ans;
        for(int i = 0; i < N; i++) for(int j = i + 1; j < N; j++) {
            int f = (mp.find(-(nums[i] + nums[j])) != mp.end()) ? mp[-(nums[i] + nums[j])] : -1;
            if(f != -1 && f > j) {
                vector<int> a = {nums[i], nums[j] , nums[f]};
                sort(a.begin(), a.end());
                ans.insert(a);
            }
        }
        vector<vector<int>> rans;
        for(auto a : ans) rans.push_back(a);
        return rans;
	}
};

int main() {
	// function<void(vector<int> &vec)> print_vector = [](vector<int> &vec) {
	// 	const int N = (int) vec.size();
	// 	for(int i = 0; i < N; i++)
	// 		cout << i << (i == N-1 ? '\n' : ' ');
	// 	return;
	// };
	vector<int> nums = {-1, 0, 1, 2, -1, -4};
	vector<vector<int>> solution = Solution().threeSum(nums);
	for(vector<int> &vec : solution)
		print_vector(vec);
	return 0;
}