#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        const int N = (int) strs.size();
        string output = strs[0];
        for(int i = 0; i < N; i++) {
            int j = 0;
            for(; j < (int) strs[i].size(); j++) if(output[j] != strs[i][j]) break;
            output = output.substr(0,j);
            if(output == "")
                return output;
        }
        return output;
    }
};

int main() {
	vector<string> strs = {
		"flower",
		"flow",
		"flight"
	};
	cout << Solution().longestCommonPrefix(strs) << '\n';
	return 0;
}