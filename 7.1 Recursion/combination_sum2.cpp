#include <bits/stdc++.h>
using namespace std;

void uniqueCombinations(int idx, vector<int> &arr, vector<int> &ds, vector<vector<int>> &ans, int target) {

	if (target == 0) {
		ans.push_back(ds);
		return;
	}


	for (int i = idx; i < arr.size(); i++) {
		if (arr[i] > target)break;
		if (i > idx && arr[i] == arr[i - 1])continue;

		ds.push_back(arr[i]);
		uniqueCombinations(i + 1, arr, ds, ans, target - arr[i]);
		ds.pop_back();

	}

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
	vector<int>ds;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		arr.push_back(temp);
	}

	sort(arr.begin(), arr.end());
	vector<vector<int>> ans;
	uniqueCombinations(0, arr, ds, ans, k);


	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[i].size(); j++) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
}


