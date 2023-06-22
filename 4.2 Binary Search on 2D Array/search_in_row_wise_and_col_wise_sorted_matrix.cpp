#include <bits/stdc++.h>
using namespace std;


bool searchInMatrix(vector<vector<int>>&matrix, int target) {
	int row = matrix.size();
	int col = matrix[0].size();

	int left = 0;
	int right = row * col - 1;

	while (left <= right) {
		int mid = left + ((right - left) >> 2);
		int curr = arr[mid / col][mid % col];

		if (curr == target)return true;

		else if (curr > target) {
			if ()
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
	int n, m, k, temp;
	cin >> n >> m >> k;
	vector<vector<int>> matrix;
	for (int i = 0; i < n; i++) {
		vector<int>row;
		for (int j = 0; j < m; j++) {
			cin >> temp;
			row.push_back(temp);
		}

		matrix.push_back(row);
	}

	bool ans = searchInMatrix(matrix, k);
	cout << ans << endl;
}