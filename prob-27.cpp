#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        const int N = (int) nums.size();
        int cnt = 0;
        for(int i = N - 1; i >= 0; i--) if(nums[i] == val) {
            // cout << "i: " << i << '\n';
            cnt++;
            int j = i + 1;
            while(j < N && nums[j] != val) {
                nums[j - 1] = nums[j];
                j++;
            }
            nums[j - 1] = val;
            // cout << "j: " <<  j-1 << '\n';
        }
        return N-cnt;
    }
};