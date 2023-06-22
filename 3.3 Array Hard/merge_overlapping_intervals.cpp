#include <bits/stdc++.h>
using namespace std;

bool comp(vector<int>&a, vector<int>& b) {
	if (a[0] < b[0])return true;

	else if (a[0] == b[0]) {
		return a[1] <= b[1];
	}
	else return false;
}


vector<vector<int>> mergeIntervals(vector<vector<int>>& arr) {
	int n = arr.size();

	// sort the array if not sorted earlier.
	sort(arr.begin(), arr.end(), comp);

	vector<vector<int>>ans;

	// loop through all the intervals
	for (int i = 0; i < n; i++) {

		if (i == 0)ans.push_back(arr[i]);

		// check if it can be merged into previous interval
		if (ans[idx][1] >= arr[i][0]) {
			ans[idx][1] = max(arr[i][1], ans[idx][1]);
		}

		else {
			ans.push_back(arr[i]);
			idx++;
		}
	}

	return ans;

	// TC --> O(n*logn) + O(n) (sorting the array + traversing in the array).
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