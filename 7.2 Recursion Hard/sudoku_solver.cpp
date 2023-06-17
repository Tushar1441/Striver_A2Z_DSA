#include <bits/stdc++.h>
using namespace std;

bool isPossible(int row, int col, int k, vector<vector<char>>&board) {

	for (int i = 0; i < 9; i++) {

		if (board[i][col] == k)return false;
		if (board[row][i] == k)return false;

		if (board[3 * (row / 3) + (i / 3)][3 * (col / 3) + (i % 3)] == k) return false;
	}

	return true;
}

bool solveSudoku(vector<vector<char>> &board) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (board[i][j] == '.') {
				for (char k = '1'; k <= '9'; k++) {
					if (isPossible(i, j, k, board)) {
						board[i][j] = k;
						if (solveSudoku(board))return true;
						else board[i][j] = '.';
					}
				}
				return false;
			}
		}
	}

	return true;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	char temp;
	vector<vector<char>> input;

	for (int i = 0; i < 9; i++) {
		vector<char>row;
		for (int j = 0; j < 9; j++) {
			cin >> temp;
			row.push_back(temp);
		}
		input.push_back(row);
	}

	solveSudoku(input);

	for (int i = 0; i < 9; i++) {
		vector<char>row;
		for (int j = 0; j < 9; j++) {
			cout << input[i][j] << " ";
		}
		cout << endl;
	}


}


