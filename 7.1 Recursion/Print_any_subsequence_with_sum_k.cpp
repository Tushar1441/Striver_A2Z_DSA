#include <bits/stdc++.h>
using namespace std;


bool subsequencewithSumK(int idx, int n, vector<int> &ans, vector<int> &arr, int k, int sum) {

	if (idx >= n) {

		// if condition satisfies
		if (sum == k) {
			for (auto it : ans)cout << it << " ";
			cout << endl;
			return true;
		}

		// if condition is not satisfied
		return false;
	}


	// pick the ith element in the subsequence
	sum += arr[idx];
	ans.push_back(arr[idx]);
	if (subsequencewithSumK(idx + 1, n, ans, arr, k, sum ) == true)return true;

	// not pick the answer element in the subsequence
	sum -= arr[idx];
	ans.pop_back();
	if (subsequencewithSumK(idx + 1, n, ans, arr, k, sum ) == true) return true;


	return false;

	// TC --> O(2^n) * O(n)  (total recursion calls * printing the answer every time)
	// SC --> O(n)  recursion stack space.
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

	subsequencewithSumK(0, n, ans, arr, k, 0);
}


