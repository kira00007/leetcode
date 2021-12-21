// for this solution to work on leetcode just make board = ans after calling the _fill(*parameters*) function

#include <bits/stdc++.h>
using namespace std;

void print_mat(vector<vector<char>> &board) {
	for(int i = 0; i < 9; i++) {
		for(int j = 0; j < 9; j++)
			cout << board[i][j] << (j == 8 ? '\0' : ' ');
		cout << '\n';
	}
}

// bool _fill(vector<vector<char>> &ans, vector<vector<char>> &board, int i, int j) {
// 	if(board[i][j] != '.') {
// 		if(i == 8 && j == 8) return true;
// 		return (j == 8 ? _fill(ans, board, i+1, 0) : _fill(ans, board, i, j+1));
// 	}
// 	set<char> possible_val = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
// 	// calculate possible_val
// 	for(int it = 0; it < 9; it++) possible_val.erase(ans[it][j]);
// 	for(int it = 0; it < 9; it++) possible_val.erase(ans[i][it]);
// 	int r = i / 3 * 3;
// 	int c = j / 3 * 3;
// 	for(int st = r; st < r + 3; st++) for(int av = c; av < c + 3; av++) possible_val.erase(ans[st][av]);

// 	if(possible_val.empty()) return false;
// 	cout << "possible values for (" << i << ", " << j << "): ";
// 	for(char val : possible_val) cout << val << ' ';
// 	cout << '\n';

// 	for(char val : possible_val) {
// 		ans[i][j] = val;
// 		if(i == 8 && j == 8) return true;
// 		else {
// 			bool works = (j == 8 ? _fill(ans, board, i+1, 0) : _fill(ans, board, i, j+1));
// 			if(works) return true;
// 		}
// 	}
// 	ans[i][j] = '.';
// 	return false;
// }

vector<vector<char>> solve(vector<vector<char>> &board) {
	vector<vector<char>> ans = board;
	function<bool(int, int)> _fill = [&](int i, int j) {
		if(board[i][j] != '.') {
			if(i == 8 && j == 8) return true;
			return (j == 8 ? _fill(i+1, 0) : _fill(i, j+1));
		}
		set<char> possible_val = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
		// calculate possible_val
		for(int it = 0; it < 9; it++) possible_val.erase(ans[it][j]);
		for(int it = 0; it < 9; it++) possible_val.erase(ans[i][it]);
		int r = i / 3 * 3;
		int c = j / 3 * 3;
		for(int st = r; st < r + 3; st++) for(int av = c; av < c + 3; av++) possible_val.erase(ans[st][av]);

		if(possible_val.empty()) return false;
		// cout << "possible values for (" << i << ", " << j << "): ";
		// for(char val : possible_val) cout << val << ' ';
		// cout << '\n';

		for(char val : possible_val) {
			ans[i][j] = val;
			if(i == 8 && j == 8) return true;
			else {
				bool works = (j == 8 ? _fill(i+1, 0) : _fill(i, j+1));
				if(works) return true;
			}
		}
		ans[i][j] = '.';
		return false;
	};
	// cout << (_fill(ans, board, 0, 0) ? "true\n" : "false\n");
	// cout << (_fill(0, 0) ? "true\n" : "false\n");
	_fill(0, 0);
	return ans;
}

int main() {
	vector<vector<char>> board = {
		{'5','3','.','.','7','.','.','.','.'},
		{'6','.','.','1','9','5','.','.','.'},
		{'.','9','8','.','.','.','.','6','.'},
		{'8','.','.','.','6','.','.','.','3'},
		{'4','.','.','8','.','3','.','.','1'},
		{'7','.','.','.','2','.','.','.','6'},
		{'.','6','.','.','.','.','2','8','.'},
		{'.','.','.','4','1','9','.','.','5'},
		{'.','.','.','.','8','.','.','7','9'},
	};
	vector<vector<char>> solved = solve(board);
	print_mat(board);
	cout << '\n';
	print_mat(solved);
	return 0;
}