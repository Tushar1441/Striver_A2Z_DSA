#include <bits/stdc++.h>
using namespace std;



bool solve(int idx, int i, int j, vector<vector<char>> &board, string word, int n, int m) {
	if (idx == word.size())return true;
	if (i < 0 || j < 0 || i == n || j == m || board[i][j] != word[idx])return false;

	char ch = board[i][j];
	board[i][j] = '#';
	bool op1 = solve(idx + 1, i + 1, j, board, word, n, m);
	bool op2 = solve(idx + 1, i - 1, j, board, word, n, m);
	bool op3 = solve(idx + 1, i , j + 1, board, word, n, m);
	bool op4 = solve(idx + 1, i , j - 1, board, word, n, m);
	board[i][j] = ch;

	return (op1 || op2 || op3 || op4);
}

bool exist(vector<vector<char>>&board , string word) {
	int n = board.size();
	int m = board[0].size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == word[0]) {
				if (solve(0, i, j, board, word, n, m))return true;
			}
		}
	}

	return false;
}



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	int m, n;
	char temp;
	string word;
	cin >> n >> m;
	vector<vector<char>>input;
	for (int i = 0; i < n; i++) {
		vector<char>row;
		for (int j = 0; j < m; j++) {
			cin >> temp;
			row.push_back(temp);
		}
		input.push_back(row);
	}
	cin >> word;
	bool ans = exist(input, word);
	cout << ans << endl;
}


