#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int link[20000], sz[20000];
	int find(int u) {
		while(u != link[u]) u = link[u];
		return u;
	}
	int join(int u, int v) {
		u = link[u];
		v = link[v];
		if(sz[u] < sz[v])
			swap(u,v);
		sz[u] += sz[v];
		link[v] = u;
		return sz[u];
	}
    int largestComponentSize(vector<int>& nums) {
		const int N = (int) nums.size();
		if(N < 2) return N;
        for(int i = 0; i < N; i++) link[i] = i;
		for(int i = 0; i < N; i++) sz[i] = 1;
		vector<vector<int>> edges;
		for(int i = 0; i < N; i++) for(int j = i + 1; j < N; j++)
			if(__gcd(nums[i], nums[j]) > 1)
				edges.emplace_back(i, j);
		int ans = 0, check = 0;
		for(int i = 0; i < (int) edges.size(); i++) {
			if(find(edges[i][0]) != find(edges[i][1])) {
				ans = max(ans, join(edges[i][0], edges[i][1]));
				check++;
			}
			if(check == N-1) break;
		}
		return ans;
    }
};

int main() {
	vector<int> nums = {2, 4};
	cout << Solution().largestComponentSize(nums) << '\n';
	return 0;
}