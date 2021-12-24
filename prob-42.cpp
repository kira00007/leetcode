#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int> &a) {
        const int n = (int)a.size();
        if(n < 3) return 0;
        int ans = 0;
        set<pair<int,int>> _int;
        for(int i = 0; i < n; i++) {
            if(i < n-1 && a[i] > a[i + 1]) {
                int r = i + 1;
                while(r < n && a[r] < a[i]) r++;
                if(r >= n || a[r] < a[i]) {
                    i = r - 1;	
                    continue;
                }
                pair<int,int> interval = {min(i,r), max(i,r)};
                if(_int.find(interval) != _int.end()) {
                    i = r - 1;
                    continue;
                }
                else
                    _int.insert(interval);
                ans += min(a[i], a[r]) * (r - i - 1);
                for(int k = i + 1; k < r; k++) ans -= min(min(a[i], a[r]), a[k]);
                cout << "values: ";
                cout << a[i] << ' ' << a[r] << '\n';
                cout << i << ' ' << r << ' ' << ans << '\n';
                i = r - 1;
            }
        }
        for(int i = n-1; i >= 0; i--) {
            if(i && a[i] > a[i - 1]) {
                int r = i - 1;
                while(r && a[r] < a[i]) r--;
                if(r < 0 || a[r] < a[i]) {
                    i = r + 1;
                    continue;
                }
                pair<int,int> interval = {min(i,r), max(i,r)};
                if(_int.find(interval) != _int.end()) {
                    i = r + 1;
                    continue;
                }
                else
                    _int.insert(interval);
                ans += min(a[i], a[r]) * (i - r - 1);
                for(int k = i -1; k > r; k--) ans -= min(min(a[i], a[r]), a[k]);
                cout << "values: ";
                cout << a[i] << ' ' << a[r] << '\n';
                cout << i << ' ' << r << ' ' << ans << '\n';
                i = r + 1;
            }
        }
        return ans;
    }
};

int main() {
	// vector<int> a = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	// vector<int> a = {4, 2, 0, 3, 2, 5};
	// vector<int> a = {5,4,1,2};
	vector<int> a = {2, 1, 0, 2};
	// vector<int> a = {1, 2};
	cout << Solution().trap(a) << '\n';
	return 0;
}