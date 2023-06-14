#include <bits/stdc++.h>
using namespace std;


// using take or not take approach
void printCombinations(int idx, vector<int>ds, vector<vector<int>>&ans, int sum, int n, int k) {
	if (idx == 10) {
		if (sum == n && ds.size() == k) {
			ans.push_back(ds);
		}
		return;
	}

	ds.push_back(idx);
	printCombinations(idx + 1, ds, ans, sum + idx, n, k);
	ds.pop_back();
	printCombinations(idx + 1, ds, ans, sum, n, k);

	// TC --> O(2^n) + O(k*x) --> x is the number of unique combinations with sum n
}


// using for loop approach
void printCombinations(int idx, vector<int>ds, vector<vector<int>>&ans, int n, int k) {
	if (n < 0 || ds.size() > k)return;

	if (n == 0 && ds.size() == k) {
		ans.push_back(ds);
		return;
	}


	for (int i = idx; i < 10; i++) {
		ds.push_back(i);
		printCombinations(i + 1, ds, ans,  n - i, k);
		ds.pop_back();

	}

	// TC --> O(2^n) + O(k*x) --> x is the number of unique combinations with sum n
}




int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif
	int n, k;
	cin >> n >> k ;

	vector<int>ds;
	vector<vector<int>> ans;

	printCombinations(1, ds, ans, 0, n, k);

	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[i].size(); j++) {
			cout << ans[i][j] << " ";
		}

		cout << endl;
	}
}


