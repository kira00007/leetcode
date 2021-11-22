#include <bits/stdc++.h>
using namespace std;

struct Set {
	vector<int> link;
	vector<int> sz;
	Set(int n)
		: link(vector<int>(n,0)), sz(vector<int>(n,0))
	{
		for(int i = 0; i < n; i++) {
			link[i] = i;
			sz[i] = 1;
		}
	}
	int find(int u) {
		while(link[u] != u) u = link[u];
		return u;
	}
	void join(int u, int v) {
		u = find(u);
		v = find(v);
		if(sz[u] < sz[v])
			swap(u,v);
		sz[u] += sz[v];
		link[v] = u;
	}
};

class Solution {
public:
	int manhattan_distance(vector<int> &point1, vector<int> &point2) {
		return abs(point1[0] - point2[0]) + abs(point1[1] - point2[1]);
	}
    int minCostConnectPoints(vector<vector<int>>& points) {
		const int N = (int) points.size();
		priority_queue<vector<int>> edges;
		for(int i = 0; i < N-1; i++) for(int j = i + 1; j < N; j++) {
			if(i == j) continue;
			edges.push({-manhattan_distance(points[i], points[j]), i, j});
		}
		cout << "total edges: " << edges.size() << '\n';
		int ans = 0;
		Set s(N);
		while(!edges.empty()) {
			vector<int> t = edges.top();
			edges.pop();
			if(s.find(t[1]) != s.find(t[2])) {
				s.join(t[1], t[2]);
				ans -= t[0];
			}
		}
		return ans;
    }
};

int main() {
	// vector<vector<int>> points = {
	// 	{3,12},
	// 	{-2,5},
	// 	{-4,1}
	// };
	// vector<vector<int>> points = { {-1000000,-1000000},{1000000,1000000} };
	// vector<vector<int>> points = { {0,0} };
	// vector<vector<int>> points = { {0,0},{1,1},{1,0},{-1,1} };
	vector<vector<int>> points = { {0,0},{2,2},{3,10},{5,2},{7,0} };
	int ans = Solution().minCostConnectPoints(points);
	cout << ans << '\n';
	return 0;
}