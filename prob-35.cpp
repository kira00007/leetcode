#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int lo = 0, hi = (int) nums.size();
        while(lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if(nums[mid] >= target) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};