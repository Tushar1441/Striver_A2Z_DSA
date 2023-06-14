#include <bits/stdc++.h>
using namespace std;


int count(int idx, int n, vector<int> &arr, int k, int sum) {

	if (idx == n) {
		if (sum == k) return 1;
		return 0;
	}


	// pick the ith element in the subsequence
	sum += arr[idx];
	int l = count(idx + 1, n, arr, k, sum);


	// not pick the answer element in the subsequence
	sum -= arr[idx];
	int r = count(idx + 1, n, arr, k, sum );


	return l + r;

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

	cout << count(0, n, arr, k, 0);
}


