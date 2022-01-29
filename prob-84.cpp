#include <bits/stdc++.h>
using namespace std;

void print(const char *msg, const vector<int> &vec) {
	fputs(msg, stdout);
	cout << '[';
	for(int i = 0; i < (int)vec.size(); i++)
		cout << vec[i] << (i == (int)vec.size()-1 ? "]\n" : ", ");
	return;
}

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
		const int N = (int)heights.size();
		if(N == 0) return 0;
		if(N == 1) return heights[0];
		if(N == 2) return max(heights[0], max(heights[1], 2*(min(heights[0], heights[1]))));
		vector<int> left(N), right(N);
		for(int i = 1; i < N; i++) {
			if(heights[i - 1] < heights[i])
				left[i] = 0;
			else if(heights[i - 1] == heights[i])
				left[i] = left[i - 1] + 1;
			else {
				int temp = left[i - 1] + 1;
				for(int j = i-(left[i - 1]+2); j >= 0; j--) {
					if(heights[j] < heights[i]) break;
					else temp++;
				}
				left[i] = temp;
			}
		}
		for(int i = N-2; i >= 0; i--) {
			if(heights[i + 1] < heights[i])
				right[i] = 0;
			else if(heights[i + 1] == heights[i])
				right[i] = right[i] + 1;
			else {
				int temp = right[i + 1] + 1;
				for(int j = i+right[i + 1]+2; j < N; j++) {
					if(heights[j] < heights[i]) break;
					else temp++;
				}
				right[i] = temp;
			}
		}
		// print("left: ", left);
		// print("right: ", right);
		int ans = *max_element(heights.begin(), heights.end());
		for(int i = 0; i < N; i++) {
			ans = max(ans, heights[i]*(left[i]+right[i]+1));
			// cout << i << ": " << left[i] << ' ' << right[i] << ' ' << heights[i]*(left[i]+right[i]+1) << '\n';
		}
		return ans;
    }
};

int main() {
	vector<vector<int>> test_cases = {
		{2, 1, 5, 6, 2, 3},
		{2, 4},
		{0, 2, 0},
	};
	for(vector<int> &test_case : test_cases) {
		cout << "\n\n";
		print("input: ", test_case);
		cout << "output: " << Solution().largestRectangleArea(test_case);
		cout << "\n\n";
	}
	return 0;
}

// [1, 2, 3, 4, 5, 6, 7, 8, 10]
// []