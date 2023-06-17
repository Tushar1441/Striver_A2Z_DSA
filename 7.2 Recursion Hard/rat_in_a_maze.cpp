#include <bits/stdc++.h>
using namespace std;

void solve(int i, int j, vector<string> &ans, string &path, vector<vector<int>> arr, int n) {
	if (i == n - 1 && j == n - 1) {
		ans.push_back(path);
		return;
	}

	if (i < 0 || j < 0 || i == n || j == n || arr[i][j] != 1) return;


	arr[i][j] = -1;
	path.push_back('D');
	solve(i + 1, j,  ans, path, arr, n);
	path.pop_back();

	path.push_back('L');
	solve(i, j - 1, ans, path, arr, n);
	path.pop_back();

	path.push_back('R');
	solve(i, j + 1, ans, path, arr, n);
	path.pop_back();

	path.push_back('U');
	solve(i - 1, j, ans, path, arr, n);
	path.pop_back();

}


vector<string> findPath(vector<vector<int>>& arr, int n) {
	string path = "";
	vector<string> ans;
	solve(0, 0, ans, path, arr, n);
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
	cin >> n;
	vector<vector<int>>input;
	for (int i = 0; i < n; i++) {
		vector<int>row;
		for (int j = 0; j < n; j++) {
			cin >> temp;
			row.push_back(temp);
		}
		input.push_back(row);
	}

	vector<string> ans = findPath(input, n);

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << endl;
	}

}


