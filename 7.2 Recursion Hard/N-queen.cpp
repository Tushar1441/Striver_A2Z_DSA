#include <bits/stdc++.h>
using namespace std;

bool canFill(int row, int col, vector<string>&ds, int n) {
	int ro = row;
	int co = col;

	// checking all upper left diagonal places on the board.
	while (row >= 0 && col >= 0) {
		if (ds[row][col] == 'Q')return false;
		row--;
		col--;
	}

	// checking all the left columns of the row on the board.
	row = ro; col = co;
	while (col >= 0) {
		if (ds[row][col] == 'Q')return false;
		col--;
	}

	// checking all the bottom left diagonal places on the board.
	col = co;
	while (row < n && col >= 0) {
		if (ds[row][col] == 'Q')return false;
		row++;
		col--;
	}

	return true;
}


// Method 1 --> using a function to check if we can place a queen on the chessboard.
vector<vector<string>> solveNQueens1(int n) {
	vector<vector<string>> ans;
	vector<string>ds(n);
	string s(n, '.');
	for (int i = 0; i < n; i++) {
		ds[i] = s;
	}
	solve1(0, ds, ans, n);
	return ans;

	// TC --> O(n^2 * 3n)  (n^2 for traversing all the places and 3n
	// to check if we can place a queen on that place.)
}

void solve1(int col,  vector<string>ds, vector<vector<string>>&ans, int n) {
	if (col == n) {
		ans.push_back(ds);
		return;
	}

	// placing the queen on every column.
	// In every col,there are row number of places, so checking all the rows.
	for (int row = 0; row < n; row++) {
		// if queen can be placed on row th position, then move to the next col.
		if (canFill(row, col, ds, n)) {
			ds[row][col] = 'Q';
			solve(col + 1, ds, ans, n);
			ds[row][col] = '.';
		}
	}
}




// Method 2 --> using hashing to verify if we can place the queen on the chessboard.
vector<vector<string>> solveNQueens2(int n) {
	vector<vector<string>> ans;
	vector<string>ds(n);
	string s(n, '.');
	for (int i = 0; i < n; i++) {
		ds[i] = s;
	}
	vector<int>leftrow(n, 0);
	vector<int>upperDiagonal(2 * n - 1, 0);
	vector<int>lowerDiagonal(2 * n - 1, 0);
	solve2(0, ds, ans, leftrow, lowerDiagonal, upperDiagonal, n);
	return ans;

	// TC --> O(n^2)

}

void solve2(int col,  vector<string>ds, vector<vector<string>>&ans, vector<int>&leftrow,
            vector<int> &lowerDiagonal, vector<int>&upperDiagonal, int n) {
	if (col == n) {
		ans.push_back(ds);
		return;
	}

	for (int row = 0; row < n; row++) {
		if (leftrow[row] == 0 && lowerDiagonal[col + row] == 0
		        && upperDiagonal[n - 1 + col - row] == 0) {

			ds[row][col] = 'Q';
			leftrow[row] = 1;
			lowerDiagonal[col + row] = 1;
			upperDiagonal[n - 1 + col - row] = 1;
			solve2(col + 1, ds, ans, leftrow, lowerDiagonal, upperDiagonal, n);
			ds[row][col] = '.';
			leftrow[row] = 0;
			lowerDiagonal[col + row] = 0;
			upperDiagonal[n - 1 + col - row] = 0;

		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	int n;
	cin >> n;

	vector < vector<string>>ans = solveNQueens(n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}

}


