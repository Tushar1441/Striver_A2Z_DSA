#include <bits/stdc++.h>
using namespace std;


// Brute Force Solution
int maximumOnesRow(vector<vector<int>>&arr) {
	int n = arr.size();
	int m = arr[0].size();
	int ans = -1; // index of row with max 1's
	int maxi = 0; // keep track of the max ones

	for (int i = 0; i < n; i++) {
		int cnt = 0;
		if (arr[i][m - 1] != 0) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] == 1)cnt++;
			}
		}

		if (cnt > maxi) {
			maxi = cnt;
			ans = i;
		}
	}

	return ans;

	// TC --> O(n*m)
}




int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	int n, m, temp;
	cin >> n >> m ;
	vector<vector<int>> arr;
	for (int i = 0; i < n; i++) {
		vector<int>row;
		for (int i = 0; i < m; i++) {
			cin >> temp;
			row.push_back(temp);
		}

		arr.push_back(row);
	}

	int ans = maximumOnesRow(arr);
	cout << ans << endl;

	// for (int i = 0; i < n; i++) {
	// 	for (int j = 0; j < m; j++) {
	// 		cout << arr[i][j] << " ";
	// 	}

	// 	cout << endl;
	// }

}