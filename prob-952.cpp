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
		u = find(u);
		v = find(v);
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
		for(int i = 0; i < N-1; i++) for(int j = i + 1; j < N; j++)
			if(__gcd(nums[i], nums[j]) > 1)
				edges.push_back({i, j});
		int ans = 0;
		int check = 0;
		for(int i = 0; i < (int) edges.size(); i++) {
			if(find(edges[i][0]) != find(edges[i][1])) {
				ans = max(ans, join(edges[i][0], edges[i][1]));
				check++;
			}
			if(check == N-1) return N;
		}
		return ans;
    }
};

int main() {
	vector<int> nums = {263,392,266,141,404,279,793,283,69,927,928,33,37,422,171,302,562,394,312,187,650,958,416,193,962,325,71,585,843,974,288,184,850,979,86,219,604,733,734,737,994,101,627,56,120,377,183,126,639};
	// vector<int> nums = {6, 14, 15};
	// vector<int> nums = {2,3,6,7,4,12,21,39};
	// vector<int> nums = {99,68,70,77,35,52,53,25,62};
	cout << Solution().largestComponentSize(nums) << '\n';
	return 0;
}