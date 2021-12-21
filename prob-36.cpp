#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int cnt[9];
        for(int r = 0; r < 3; r++) for(int c = 0; c < 3; c++) {
            memset(cnt, 0, sizeof(cnt));
            for(int i = r*3; i < r*3 + 3; i++) for(int j = c*3; j < c*3 + 3; j++) {
                if(board[i][j] == '.') continue;
                cnt[board[i][j] - '0' - 1]++;
                if(cnt[board[i][j] - '0' - 1] > 1) return false;
            }
        }
        for(int i = 0; i < 9; i++) {
            memset(cnt, 0, sizeof(cnt));
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.') continue;
                cnt[board[i][j] - '0' - 1]++;
                if(cnt[board[i][j] - '0' - 1] > 1) return false;
            }
        }
        for(int i = 0; i < 9; i++) {
            memset(cnt, 0, sizeof(cnt));
            for(int j = 0; j < 9; j++){
                if(board[j][i] == '.') continue;
                cnt[board[j][i] - '0' - 1]++;
                if(cnt[board[j][i] - '0' - 1] > 1) return false;
            }
        }
        return true;
    }
};

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
	cout << (Solution().isValidSudoku(board) ? "true" : "false") << '\n';
	return 0;
}