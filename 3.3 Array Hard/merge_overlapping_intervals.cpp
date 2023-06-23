#include <bits/stdc++.h>
using namespace std;


//
vector<vector<int>> mergeIntervals(vector<vector<int>>& arr) {
	int n = arr.size();

	// sort the array if not sorted earlier.
	// it will sort the intervals in increasing order of their starting time.
	sort(arr.begin(), arr.end());

	vector<vector<int>>ans;

	// loop through all the intervals
	for (int i = 0; i < n; i++) {

		// push the first interval
		if (i == 0)ans.push_back(arr[i]);

		// check if it can be merged into previous interval
		if (ans.back()[1] >= arr[i][0]) {
			ans.back()[1] = max(arr[i][1], ans.back()[1]);
		}

		// if cannot be merged then push the interval into the array.
		else {
			ans.push_back(arr[i]);
		}
	}

	return ans;

	// TC --> O(n*logn) + O(n) (sorting the array + traversing in the array).
	// SC --> O(n*2) for storing the answer, not using any other extra space.
}




int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	int n, temp;
	cin >> n;;

	vector<vector<int>>arr;
	for (int i = 0; i < n; i++) {
		vector<int>row;
		for (int j = 0; j < 2; j++) {
			cin >> temp;
			row.push_back(temp);
		}
		arr.push_back(row);
	}

	vector<vector<int>>ans = mergeIntervals(arr);

	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < 2; j++)cout << ans[i][j] << " ";
		cout << endl;
	}
}