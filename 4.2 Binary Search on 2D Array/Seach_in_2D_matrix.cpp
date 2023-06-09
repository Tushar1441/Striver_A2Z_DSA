#include <bits/stdc++.h>
using namespace std;




// if the matrix is row-wise and column-wise sorted then
// we can treat it as a linear sorted array
bool binarySearch(vector<vector<int>> &matrix, int target) {
	int n = matrix.size();
	int m = matrix[0].size();
	int low = 0, high = n * m - 1;

	while (low <= high) {
		int mid = low + (high - low) / 2;

		if (matrix[mid / m][mid % m] == target) return true;

		else if (matrix[mid / m][mid % m] < target) low = mid + 1;

		else high = mid - 1;
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

	bool ans = binarySearch(matrix, k);
	cout << ans << endl;
}