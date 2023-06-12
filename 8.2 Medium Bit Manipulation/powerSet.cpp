#include <bits/stdc++.h>
using namespace std;


vector<vector<int>> powerSet(vector<int> &arr) {
	int n = arr.size();
	vector<vector<int>> ans;

	for (int i = 0; i < (1 << n); i++ ) {
		vector<int> temp;
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				temp.push_back(arr[j]);
			}
		}

		ans.push_back(temp);
	}

	return ans;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	int n, temp;
	cin >> n ;
	vector< int> arr;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		arr.push_back(temp);
	}
	vector<vector<int>> ans = powerSet(arr);
	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[i].size(); j++) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
}