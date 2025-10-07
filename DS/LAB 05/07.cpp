#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isSafe(vector<string>& board, int row, int col, int n) {
        for (int j = 0; j < n; j++) {
            if (board[row][j] == 'F') {
                return false;
            }
        }

        for (int i = 0; i < n; i++) {
            if (board[i][col] == 'F') {
                return false;
            }
        }

        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'F') {
                return false;
            }
        }

        for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'F') {
                return false;
            }
        }

        return true;
    }

    void placeFlags(vector<string>& board, int row, int n, vector<vector<string>>& ans) {
        if (row == n) {
            ans.push_back(board);
            return;
        }

        for (int j = 0; j < n; j++) {
            if (isSafe(board, row, j, n)) {
                board[row][j] = 'F';
                placeFlags(board, row + 1, n, ans);
                board[row][j] = '.';
            }
        }
    }

    vector<vector<string>> solveFlagProblem(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));

        placeFlags(board, 0, n, ans);
        return ans;
    }
};

int main() {
    int n = 4;
    Solution solution;
    vector<vector<string>> result = solution.solveFlagProblem(n);

    cout << "All valid flag placements:" << endl;
    for (const auto& board : result) {
        for (const auto& row : board) {
            cout << row << endl;
        }
        cout << endl;
    }

    return 0;
}
