#include <bits/stdc++.h>
using namespace std;

void printCombinations(int idx, vector<int> &arr, vector<int> &ds, vector<vector<int>> &ans1, int target) {
	if ( idx == arr.size()) {
		if (target == 0) ans1.push_back(ds);
		return;
	}

	// pick up the current element
	if (arr[idx] <= target) {
		ds.push_back(arr[idx]);
		printCombinations(idx, arr, ds, ans1, target - arr[idx]);
		ds.pop_back();
	}

	// not pick the current element and move to next idx
	printCombinations(idx + 1, arr, ds, ans1, target);

}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	int n, k, temp;
	cin >> n >> k;
	vector<int>arr;
	vector<int>ans;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		arr.push_back(temp);
	}
	vector<vector<int>> ans1;
	printCombinations(0, arr, ans, ans1, k);

	for (int i = 0; i < ans1.size(); i++) {
		for (int j = 0; j < ans1[i].size(); j++) {
			cout << ans1[i][j] << " ";
		}
		cout << endl;
	}
}


