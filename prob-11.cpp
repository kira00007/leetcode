#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int lo = 0, hi = (int)height.size()-1;
        int ans = 0;
        while(lo < hi) {
            int l = height[lo] < height[hi] ? height[lo] : height[hi];
            int ar = l * (hi - lo);
            if(ar > ans) ans = ar;
            if(height[lo] < height[hi]) lo++;
            else hi--;
        }
        return ans;
    }
};