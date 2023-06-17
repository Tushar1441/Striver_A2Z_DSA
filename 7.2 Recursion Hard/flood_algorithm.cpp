#include <bits/stdc++.h>
using namespace std;

void solve(int i, int j, vector<vector<int>> &image, int oldColor, int color, int n, int m) {
	if (i < 0 || j < 0 || i == n || j == m || image[i][j] != oldColor) return;

	image[i][j] = color;
	solve(i + 1, j, image, oldColor, color, n, m);
	solve(i - 1, j, image, oldColor, color, n, m);
	solve(i, j + 1, image, oldColor, color, n, m);
	solve(i, j - 1, image, oldColor, color, n, m);
}


vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
	int n = image.size();
	int m = image[0].size();
	int oldColor = image[sr][sc];
	if (oldColor == color)return image;

	solve(sr, sc, image, oldColor, color, n, m);
	return image;

	// TC --> O(n*m) in worst case going on all the elements.
	// SC --> O(n*m) recursion stack space in worst case.
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	int m, n, temp;
	int x, y, color;
	cin >> n >> m;
	vector<vector<int>>input;
	for (int i = 0; i < n; i++) {
		vector<int>row;
		for (int j = 0; j < m; j++) {
			cin >> temp;
			row.push_back(temp);
		}
		input.push_back(row);
	}


	cin >> x >> y >> color;

	floodFill(input, x, y, color);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << input[i][j] << " ";
		}
		cout << endl;
	}

}


